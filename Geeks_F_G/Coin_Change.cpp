// https://practice.geeksforgeeks.org/problems/coin-change2448/1#
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> t(m+1, vector<long long int>(n+1,0));
        for(long long int i=0;i<=m;i++){
            t[i][0]=1;
        }
        for(long long int i=1;i<=m;i++){
            for(long long int j=1;j<=n;j++){
                if(S[i-1]<=j){
                    t[i][j]=t[i-1][j] + t[i][j-S[i-1] ];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[m][n];
    }
};