#include<iostream>
#include<queue>
#include<vector>
#include <climits>
using namespace std;

int find_minimum_path(const vector<vector<pair<int,int>>>& graph,int source,int destination){
vector<int>distance(graph.size(),INT_MAX);
priority_queue<pair<int,int>,vector<pair<int,int>>,std::greater<pair<int,int>>>ques;
distance[source] = 0;
ques.push({0,source});
while(!ques.empty()){//i can stop when reach destination , but i find all minimum distacnes
auto [dist,vertex] = ques.top();
ques.pop();
if(dist>distance[vertex]){
 continue;
}
for(auto iter:graph[vertex]){
    if(distance[vertex]+iter.second<distance[iter.first]){
         distance[iter.first] = distance[vertex]+iter.second;
         ques.push({distance[iter.first],iter.first});
    }
}
}
return distance[destination]==INT_MAX?-1:distance[destination];
} 

int main(){
    vector<vector<pair<int,int>>>graph(8);
    graph[0].push_back({1,1});
    graph[0].push_back({3,1});
    graph[0].push_back({2,3});
    graph[1].push_back({3,3});
    graph[1].push_back({4,1});
    graph[2].push_back({6,7});
    graph[3].push_back({5,3});
    graph[3].push_back({6,1});
    graph[6].push_back({7,4});
    graph[4].push_back({5,1});
    graph[5].push_back({7,2});
   cout<<find_minimum_path(graph,0,7)<<endl;
  return 0;
}

