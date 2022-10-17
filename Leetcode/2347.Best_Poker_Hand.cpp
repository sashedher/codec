// https://leetcode.com/problems/best-poker-hand/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int> mp;
        map<int,int> mp1;
        int fls=INT_MIN;
        for(char x:suits){
            mp[x]++;
            fls=max(fls,mp[x]);
        }
        if(fls==5) return "Flush";
        for(int x:ranks) mp1[x]++;
        vector<int> fr(6,0);
        for(auto x:mp1){
            fr[x.second]=1;
        }
        
        for(int i=5;i>=0;i--){
            // cout<<fr[5-i]<<" ";
            if(fr[i]==1){
                if(i>=3) return "Three of a Kind";
                if(i>=2) return "Pair";
            }
        }
        // cout<<endl;
        return "High Card";
    }
};