//  https://www.interviewbit.com/problems/0-1-knapsack/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    int solve(vector<int> &A, vector<int> &B, int C) {
        int n=A.size(),m=C;
        vector<int> curr(m+1,0);
        vector<int> prev(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(B[i-1]<=j){
                    curr[j]=max( A[i-1]+ prev[j-B[i-1]],prev[j]);
                }
                else curr[j]=prev[j];
            }
            prev.clear();
            prev=curr;
        }

        return curr[m];
    }
};
