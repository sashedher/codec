// https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    int solve(vector<int> &A, int B) {
        int n=A.size();
        vector<bool> curr(B+1,false);
        vector<bool> prev(B+1,false);
        curr[0]=true;
        prev[0]=true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=B;j++){
                if(A[i-1]<=j)
                    curr[j]= prev[j-A[i-1]] || prev[j];
                else
                    curr[j]=prev[j];
            }
            prev.clear();
            prev=curr;
        }


        return curr[B];
    }
};