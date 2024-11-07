// https://leetcode.com/problems/first-letter-to-appear-twice/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        int n=s.length();
        vector<int> v(26,0);
        for(char x:s){
            v[x-'a']++;
            if(v[x-'a']==2) return x;
        }
        return 'a';
    }
};