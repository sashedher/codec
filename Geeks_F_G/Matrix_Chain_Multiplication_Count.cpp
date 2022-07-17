// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dp[101][101];
    int solve(int ar[],int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int mn=INT_MAX;
        for(int k=i;k<j;k++){
            int t= solve(ar,i,k)+ solve(ar,k+1,j)+ ar[i-1]*ar[k]*ar[j];
            
            if(t<mn){
                mn=t;
                
            }
            
        }
        dp[i][j]=mn;
        return mn;
    }
    
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};