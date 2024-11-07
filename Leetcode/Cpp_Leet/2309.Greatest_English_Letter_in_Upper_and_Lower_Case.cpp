// https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]]=1;
            }
            else mp[s[i]]++;
        }
        
        string res="";
        for(int i=0;i<26;i++){
           char s='a'+i,u='A'+i;
            if(mp.find(s)!=mp.end() && mp.find(u)!=mp.end()) res=u;
        }
        
        return res;
    }
};