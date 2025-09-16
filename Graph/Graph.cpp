#include<iostream>
#include<vector>
#include<unordered_map>
#include<stdexcept>
#include<stack>
#include<queue>
#include<list>
using namespace std;
// is for undirected;
class Graph{
std::vector<std::vector<int>>graph;
unordered_map<int,int> index_to_map;

public:
Graph()=default;

void addEdge( int u,int v){
    if(u >= graph.size() || v >= graph.size()) {
    throw std::out_of_range("Invalid vertex index");
}
    graph[u].push_back(v);
   //gr[v].push_back(u);
}

void addVertex(int vertex){
    int index=index_to_map.size();
    index_to_map[index]=vertex;
    graph.push_back({});
}
int getID(int index){
    auto it = index_to_map.find(index);
    if(it == index_to_map.end()){
          throw invalid_argument("there is no such index");
    }
    return it->second;
}
int size(){
    return graph.size();
}

void dfs_helper(vector<bool>& visited,int vertex){//recursive
     visited[vertex]=true; 
    for(int v:graph[vertex]){
        if(!visited[v]){
             dfs_helper(visited,v);
        }
    }
  }

  void dfs_it(vector<bool>& visited,int vertex){//iterativ
    stack<int>st;
    st.push(vertex);
    while(!st.empty()){
         int index= st.top();
          st.pop();
          visited[index]=true;
        for(int ver:graph[index]){
            if(!visited[ver]){
               st.push(ver);
            }
        }
    }
  }

  void dfs(){
    vector<bool>visited(graph.size());
    for(int i=0;i<graph.size();i++){
        if(!visited[i]){
            dfs_helper(visited,i);
        }
    }
  }
void bfs_helper(vector<bool>& visited,int ver){
   queue<int>ques;
   visited[ver] = true;
   ques.push(ver);
   while(!ques.empty()){
      int size=ques.size();
      for(int i=0;i<size;i++){
        int vert = ques.front();
         ques.pop();
         for(int x:graph[vert]){
            if(!visited[x]){
                visited[x]=true;
                ques.push(x);
            }
         }
      }

   }
}

void bfs(){
vector<bool>visited(graph.size(),false);
   for(int i=0;i<graph.size();i++){
    if(!visited[i]){
    bfs_helper(visited,i);
   }
}
}

int get_number_of_nodes_at_level(int level,int vertex){ 
 if(level == 0){
    return 1;
 }  
 vector<bool>visited(graph.size(),false);    
 queue<int>ques;
 visited[vertex] = true;
  ques.push(vertex);
 while(!ques.empty()){
    int size = ques.size();
    for(int i=0;i<size;i++){
        int ver = ques.front();
        ques.pop();
        for(int x:graph[ver]){
            if(!visited[x]){
                visited[x] = true;
                ques.push(x);
            }
        }
    }
    level--;
    if(level == 0){
        return ques.size();
    }
 }
return -1;//not found
}

void transpose(){//for directed
   vector<vector<int>>temp_graph(graph.size()); 
 for(int i=0;i<graph.size();i++){
   for(int vertex:graph[i]){
    temp_graph[vertex].push_back(i);
   }
 }
 graph.swap(temp_graph);
}


std::list<int> shortest_path_helper(vector<int>& parent,int target){
    std::list<int>result;
  while(target!=-1){
    result.push_front(target);
        target=parent[target];
  }
  return result;
} 


std::list<int> findShorthestPath(int dest,int target){
    vector<int>parent(graph.size(),-1);
    vector<bool>visited(graph.size(),false);
    queue<int>ques;
    visited[dest] = true;
    ques.push(dest);
    parent[dest] = -1;
    while(!ques.empty()){
        int size = ques.size();
        for(int i= 0;i<size;i++){
            int ver=ques.front();
            ques.pop();
            for(int vertex:graph[ver]){
                 if(vertex == target){
                    parent[vertex] = ver;
                    return shortest_path_helper(parent,target);
                 }
                if(!visited[vertex]){
                     parent[vertex]=ver;
                     visited[vertex] = true;
                     ques.push(vertex);
                }
            }
        }
    }
    return{};
}

void find_all_paths_helper(vector<vector<int>>& graph,std::vector<vector<int>>& result,vector<int>& temp,vector<bool>& visited,int source,int dest){
    visited[source] = true;
     temp.push_back(source);
     if(source == dest){
        result.push_back(temp);
        temp.pop_back();
        return ;
     }
    for(int vertex:graph[source]){
        if(!visited[vertex]){
  find_all_paths_helper(graph,result,temp,visited,vertex,dest); 
        }
    }
    visited[source] = false;
    temp.pop_back();
    return ;
}


std::vector<vector<int>> find_all_paths(int source ,int dest) {
std::vector<bool>visited(graph.size(),false);
std::vector<vector<int>>result;
std::vector<int>temp;
find_all_paths_helper(graph,result,temp,visited,source,dest);
return result;
}

bool has_cycle_helper(vector<vector<int>>& graph,vector<bool>& visited,int parent,int start_node){//undirected
    visited[start_node] = true;
    for(int vertex:graph[start_node]){
        if(visited[vertex] == true && parent!=vertex){
            return true;
        }
        if(!visited[vertex]){
            if(has_cycle_helper(graph,visited,start_node,vertex)){
                return true;
            }
        }
        
    }
    return false;
}


bool has_cycle() { //undirected
vector<bool>visited(graph.size(),false);
for(int i=0;i<graph.size();i++){
    if(!visited[i]){
        if(has_cycle_helper(graph,visited,-1,i)){
            return true;
        }
    }
}
return false;  
}

bool has_cycle_helper(vector<vector<int>>& graph,vector<bool>& Onstack,vector<bool>& visited,int node){////directed
Onstack[node] = true;
visited[node] = true;
 for(int vertex:graph[node]){
    if(Onstack[vertex]){
        return true;
    }
    if(!visited[vertex]){
        if(has_cycle_helper(graph,Onstack,visited,vertex)){
            return true;
        }
    }
 }
 Onstack[node] = false;
return false;
}

bool has_cycle(){ //directed
vector<bool>OnStack(graph.size(),false);
vector<bool>visited(graph.size(),false);
for(int i=0;i<graph.size();i++){
    if(!visited[i]){
    if(has_cycle_helper(graph,OnStack,visited,i)){
        return true;
    }
    } 
}
return false;
}

void top_sort_helper(vector<bool>& visited,stack<int>& result,int start_node){
 visited[start_node] = true;
 for(int vertex:graph[start_node]){
    if(!visited[vertex]){
        top_sort_helper(visited,result,vertex);
    }
 }
 result.push(start_node);
}

vector<int> top_sort(){/// with dfs for directed acycle
    if(has_cycle()){
        throw runtime_error("Graph has a cycle → no topological order exists");
    } 
vector<bool>visited(graph.size(),false);
stack<int>result;
vector<int>result1;
for(int i=0;i<graph.size();i++){
    if(!visited[i]){
        top_sort_helper(visited,result,i);
    }
}
while(!result.empty()){
    result1.push_back(result.top());
    result.pop();
}
return result1;

} 
///KAHNS ALGORITHM WITH INDEGREES 
vector<int> kahns_top_sort(){///with inDegrees 
vector<int>result;
int n= graph.size();
vector<int>indegree(graph.size());
for(int i=0;i<n;i++){
    for(int vertex:graph[i]){
        indegree[vertex]++;
    }
}
queue<int>vertexes;
for(int i=0;i<n;i++){
    if(indegree[i]==0){
        vertexes.push(i);
    }
}
while(!vertexes.empty()){
   int index = vertexes.front();
   result.push_back(index);
   vertexes.pop();
   for(int vertex:graph[index]){
    indegree[vertex]--;
    if(indegree[vertex]==0){
        vertexes.push(vertex);
    }
   }
}
if(result.size()!=n){
    throw runtime_error("Graph has a cycle → no topological order exists");
}
return result;

}


// SCC-KOSARAJAO

void dfs1(vector<bool>& visited,stack<int>& finishs,int start){
    visited[start] = true;
    for(int vertex:graph[start]){
        if(!visited[vertex]){
            dfs1(visited,finishs,vertex);
        }
    }
    finishs.push(start);
}

void dfs2(vector<vector<int>>& graph, vector<bool>& visited,vector<int>&comp,int start){
    comp.push_back(start);
    visited[start] = true;
    for(int vertex:graph[start]){
        if(!visited[vertex]){
            dfs2(graph,visited,comp,vertex);
        }
    }
}

vector<vector<int>> KOSARAJAO(){
stack<int>finishs;
vector<bool>visited(graph.size(),false);

 for(int i=0;i<graph.size();i++){
 if(!visited[i]){
     dfs1(visited,finishs,i); 
}
}
vector<vector<int>>temp_graph(graph.size());/////transposing 
for( int i=0;i<graph.size();i++){
    for(int vertex:graph[i]){
        temp_graph[vertex].push_back(i);
    }
}
vector<vector<int>>output;
vector<bool>visited1(graph.size(),false);
while(!finishs.empty()){
int start = finishs.top();
finishs.pop();
if(!visited1[start]){
    vector<int>comp;
    dfs2(temp_graph,visited1,comp,start);
    output.push_back(comp);
}  
}
return output;
}
//////////KASARAJOU END




////////TARJANS 

void Tarjan_helper(vector<vector<int>>& result,stack<int>& st,vector<bool>& onStack,int& id,vector<int>& ids,vector<int>&ll,int start_node){
      onStack[start_node]=true;
      st.push(start_node);
      ids[start_node] = ll[start_node] =id;
      for(int vertex:graph[start_node]){
        if(ids[vertex]==-1){
        Tarjan_helper(result,st,onStack,id,ids,ll,vertex);
        }
        if(onStack[vertex]){
            ll[start_node]=std::min(ll[start_node],ll[vertex]);
        }
      }
      if(ll[start_node]==ids[start_node]){
        vector<int>SCC;
    while(!st.empty()){
        if(st.top() == start_node){
            SCC.push_back(start_node);
            result.push_back(SCC);     
            st.pop();
            onStack[start_node]=false;
            break;
        }
        SCC.push_back(st.top());
         onStack[st.top()]=false;
        st.pop();
        
    }
      }  
}

vector<vector<int>> TARJANS(){
vector<vector<int>>result;
stack<int>st;
vector<bool>onStack(graph.size(),false);
int id=0;
vector<int>ids(graph.size(),-1);
vector<int>ll(graph.size());
for(int i=0;i<graph.size();i++){
    if(ids[i] == -1){
        Tarjan_helper(result,st,onStack,id,ids,ll,i);
    }
} 
return result;

}
//////END TARJAN











  

  
  











};
















