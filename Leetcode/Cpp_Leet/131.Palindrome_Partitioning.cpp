// https://leetcode.com/problems/palindrome-partitioning/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string &x,int i,int j){
        while(i<j){
            if(x[i]!=x[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void Backtrack(vector<vector<string>> &res,vector<string> &ans,int ind,int n,string s){
        if(ind==n){
            res.push_back(ans);
            return;
        }
        
        for(int i=ind;i<n;i++){
            if(palindrome(s,ind,i)){
                string x(s.begin()+ind,s.begin()+i+1);
                ans.push_back(x);
                Backtrack(res,ans,i+1,n,s);
                ans.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        Backtrack(res,ans,0,s.length(),s);
        
        return res;
    }
};