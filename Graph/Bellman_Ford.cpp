#include<iostream>
#include<vector>
#include<climits>
#include<exception>
std::vector<int> Bellman_Ford(int source,std::vector<std::vector<int>>& edges,int n){

std::vector<int>distance(n,INT_MAX);
 distance[source] = 0;
for(int i = 0 ; i < n-1 ; i++){
  for(int j = 0; j < edges.size();j++){  
    int from = edges[j][0];
    int to = edges[j][1];
    int dist = edges[j][2];
    if(distance[from]!= INT_MAX && distance[from] + dist<distance[to]){
        distance[to] = distance[from] + dist;
    }
 }
}
  for(int j = 0; j < edges.size();j++){  
    int from = edges[j][0];
    int to = edges[j][1];
    int dist = edges[j][2];
    if(distance[from]!= INT_MAX && distance[from] + dist<distance[to]){
        throw std:: invalid_argument("there is negative cycle");
    }
 }
 return distance;
}











