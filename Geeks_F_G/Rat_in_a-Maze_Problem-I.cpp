// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rat-in-a-maze-problem

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void solve(vector<vector<int>> &m, int i,int j, int n, string &ans, vector<string> &res){
        if(i<0 ||j<0|| i==n|| j==n|| m[i][j]!=1) return;
        
        if(i==n-1 && j==n-1){
            res.push_back(ans);
            return;
        }
        
        
        
        int x=m[i][j];
        m[i][j]=2;
        ans.push_back('U');
        solve(m,i-1,j,n,ans,res);
        ans.pop_back();
        
        ans.push_back('D');
        solve(m,i+1,j,n,ans,res);
        ans.pop_back();
        
        ans.push_back('L');
        solve(m,i,j-1,n,ans,res);
        ans.pop_back();
        
        ans.push_back('R');
        solve(m,i,j+1,n,ans,res);
        ans.pop_back();
        
        m[i][j]=x;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string ans="";
        solve(m,0,0,n,ans,res);
        return res;
    }
};
