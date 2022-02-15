// https://www.interviewbit.com/problems/subset-sum-problem/

#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    int solve(vector<int> &A, int B) {
    vector<vector<int>> t(A.size()+1,vector<int>(B+1,0));
    for(int i=0;i<=A.size();i++){
        t[i][0]=1;
    }
    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=B;j++){
            if(A[i-1]<=j){
                t[i][j]=t[i-1][j-A[i-1]] || t[i-1][j];
            }
            else t[i][j]=t[i-1][j];
        }
    }
    return t[A.size()][B];
}
};