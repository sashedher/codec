// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
      vector<int> A(arr,arr+N);
      int x=accumulate(A.begin(),A.end(),0);
      if(x%2==1) return 0;
      else return solve(A,x/2);
    }
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