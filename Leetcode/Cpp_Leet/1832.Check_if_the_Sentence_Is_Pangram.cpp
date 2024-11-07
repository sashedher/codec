// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(char x:sentence){
            v[x-'a']++;
        }        
        for(int x:v){
            if(x<1) return false;
        }
        return true;
    }
};