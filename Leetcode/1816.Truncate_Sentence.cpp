// https://leetcode.com/problems/truncate-sentence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        int n=s.length(),i=0;
        k--;
        for(i=0;i<n;i++){
            if(s[i]==' '){
                if(k>0) k--;
                else break;
            }
        }
        s.erase(i);
        return s;
    }
};