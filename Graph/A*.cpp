#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>
#include <climits>
using namespace std;
int h(int x,int y,int x1,int y1){
    return abs(x-x1)+abs(y-y1);
}

vector<pair<int,int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
int find_small_path(vector<vector<int>>&grid,pair<int,int>start,pair<int,int>end){
   int  end_x = end.first;
    int end_y = end.second;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
    distance[start.first][start.second] = 0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>>ques;
    ques.push({0,start});
    while(!ques.empty()){
     auto [dist,current] = ques.top();
     int x = current.first;
      int y = current.second;
     ques.pop();
     if(distance[x][y]<dist){
        continue;
     }
     if(current == end){
        return distance[x][y];     ///////x== i y==j
     } 
     for(auto[move_x,move_y]:directions){
        int temp_distance = distance[x][y]+1;
        int new_x= x+move_x;
        int new_y = y+move_y;
    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]!= 1 && temp_distance<distance[new_x][new_y]){
        distance[new_x][new_y] = temp_distance;
        ques.push({temp_distance+h(end_x,end_y,new_x,new_y),{new_x,new_y}});
    }

     }
    }
    return -1;
}






