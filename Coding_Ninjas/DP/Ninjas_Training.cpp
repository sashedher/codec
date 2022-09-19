// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int MaxTrain(vector<vector<int>>& p,int n, int k,vector<vector<int>> &dp){
    if(n==0){
        int mx=0;
        for(int i=0;i<3;i++){
            if(i!=k) mx=max(mx,p[n][i]); 
        }
        return dp[n][k]=mx;
    }
    if(dp[n][k]!=-1) return dp[n][k];
    int mx=0;
    for(int i=0;i<3;i++){
        if(i!=k){
            int r=p[n][i]+MaxTrain(p,n-1,i,dp);
            mx=max(r,mx);                
        }
    }
    return dp[n][k]=mx;
   
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max({points[0][0],points[0][1],points[0][2]});
    
    for(int i=1;i<n;i++){
        
        for(int j=0;j<4;j++){
            int mx=0;
            for(int k=0;k<3;k++){
                if(j!=k){
                    int r=points[i][k]+dp[i-1][k];
                    mx=max(mx,r);
                }
            }
            dp[i][j]=mx;
        }
    }
    
//     return MaxTrain(points,n-1,3,dp);
    return dp[n-1][3];
}
