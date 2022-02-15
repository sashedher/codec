 
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    int solve(vector<int> &A, vector<int> &B, int C) {
        vector<vector<int>> t(A.size()+1,vector<int>(C+1,0));
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=C;j++){
                if(B[i-1]<=j){
                    t[i][j]=max(A[i-1]+t[i-1][j-B[i-1]],t[i-1][j]);
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[A.size()][C];
    }
};
