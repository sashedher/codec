// https://leetcode.com/problems/find-original-array-from-doubled-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2) return {};
        map<int,int> mp;
        sort(changed.begin(), changed.end());
        vector<int> res;
        
        for(int x:changed) mp[x]++;
        
        for(int i=0;i<n;i++){
            if(mp[changed[i]]==0) continue;
            else{
                if(mp[2*changed[i]]==0) return {};
                else{
                    res.push_back(changed[i]);
                    mp[changed[i]]--;
                    mp[2*changed[i]]--;
                    
                }
            }
        }
        return res;
    }
};