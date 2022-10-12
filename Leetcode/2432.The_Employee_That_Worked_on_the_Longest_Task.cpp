// https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        vector<int> mp(n,0);
        int n1= logs.size(),id,tm=0,x=0;
        for(int i=0;i<n1;i++){
            mp[logs[i][0]]=max(mp[logs[i][0]], logs[i][1]-x );
            x=logs[i][1];
        }
        for(int i=0;i<n;i++){
            if(tm<mp[i]){
                tm=mp[i];
                id=i;
            } 
        }
        return id;
    }
};