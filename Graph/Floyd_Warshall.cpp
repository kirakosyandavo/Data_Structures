#include<iostream>
#include<vector>
#include<climits>
std::vector<std::vector<int>> Floyd_Warshall(std::vector<std::vector<int>>& edges,int n){
    std::vector<std::vector<int>>dp(n,std::vector<int>(n,INT_MAX));
    for(int i = 0; i<n;i++){
        dp[i][i] = 0;
    }
    for(int i = 0;i<edges.size();i++){
        int from = edges[i][0];
        int to = edges[i][1];
        int weight = edges[i][2];
        dp[from][to] = weight;
    }
    
    for(int k = 0;k < n;k ++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ;j++){
              if(dp[i][k]!= INT_MAX && dp[k][j]!= INT_MAX){
                dp[i][j] = std::min(dp[i][k]+dp[k][j],dp[i][j]);
              }  
        }
    } 
} 
return dp;
}
