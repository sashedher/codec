// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n=s.size(),res=0,j=0;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end())    j=max(j,mp[s[i]]+1);                //update j only greater than prev one
            
            mp[s[i]]=i;
            res=max(res,i-j+1);
        }
        return res;
    }
};