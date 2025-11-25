#include<iostream>
#include<vector>
#include<array>
#include<queue>
using namespace std;
// Cat start from 1
// Mouse start from 2 
static const int MOUSE_TURN = 0;
static const int CAT_TURN = 1;
static const int DRAW = 0;
static int MOUSE_WIN = 1;
static int CAT_WIN = 2;

int catMouseGame(vector<vector<int>>& graph){
  int n = graph.size();
  // color[m][c][t] = DRAW(0), MOUSE_WIN(1), CAT_WIN(2)
  vector<vector<vector<int>>>color(n,vector<vector<int>>(n,vector<int>(2,0)));
  // degree[m][c][t] = number of moves available to current player
  vector<vector<vector<int>>>degree(n,vector<vector<int>>(n,vector<int>(2,0)));
   queue<array<int,3>> q;
   // precompute degrees
  for(int m = 0 ;m<n;m++){
    for(int c = 0; c<n;c++){
         degree[m][c][MOUSE_TURN] = graph[m].size();
         int count = 0;
         for(auto vertex:graph[c]){
            if(vertex!= 0){
                count++;
            }
         }
         degree[m][c][CAT_TURN] = count;
    }
  }
  // the cat winning states
  for(int i = 0 ;i<n;i++){
    color[i][i][MOUSE_TURN] = CAT_WIN;
    color[i][i][CAT_TURN] = CAT_WIN;
    q.push({i,i,MOUSE_TURN});
    q.push({i,i,CAT_TURN});
  }
  // the mouse winning states 
  for(int i = 0; i<n;i++){
     color[0][i][MOUSE_TURN] = MOUSE_WIN;
     color[0][i][CAT_TURN] = MOUSE_WIN;
    q.push({0,i,MOUSE_TURN});
    q.push({0,i,CAT_TURN});
  }
  while(!q.empty()){
     
   auto[m,c,t] = q.front();q.pop();
   int result = color[m][c][t];
   if(t == MOUSE_TURN){
    for(auto c_prev:graph[c]){
         if(c_prev == 0){continue;}
         int m_prev = m;
         int t_prev = CAT_TURN;
         if(color[m_prev][c_prev][t_prev]!=DRAW){continue;}
         if(result==CAT_WIN){
            color[m_prev][c_prev][t_prev] = CAT_WIN;
            q.push({m_prev,c_prev,t_prev});
         }
         else{  // bad for cat
            degree[m_prev][c_prev][t_prev]--;
            if(degree[m_prev][c_prev][t_prev]==0){
                 color[m_prev][c_prev][t_prev] = MOUSE_WIN;
                 q.push({m_prev,c_prev,t_prev});
            }             
         }
      }
   } 
   if(t == CAT_TURN){
    for(auto m_prev:graph[m]){
         int t_prev = MOUSE_TURN;
         int c_prev = c;
         if(color[m_prev][c_prev][t_prev]!=DRAW){continue;}
         if(result == MOUSE_WIN){
            color[m_prev][c_prev][t_prev] = MOUSE_WIN;
            q.push({m_prev,c_prev,t_prev});
         }
         else{
            degree[m_prev][c_prev][t_prev]--;
            if(degree[m_prev][c_prev][t_prev]==0){
                q.push({m_prev,c_prev,t_prev});
               color[m_prev][c_prev][t_prev] = CAT_WIN;
            }
         }         
        }
    }
    }
    return color[1][2][MOUSE_TURN];
   }









