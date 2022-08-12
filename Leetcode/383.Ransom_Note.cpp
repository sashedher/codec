// https://leetcode.com/problems/ransom-note/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26,0);
        for(char x:magazine){
            mp[x-'a']++;
        }
        for(char x:ransomNote){
            if(mp[x-'a']==0) return false;
            mp[x-'a']--;
        }
        return true;
    }
};