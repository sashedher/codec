// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        int n1 = word2.size(), n2 = word2.size();
        for(string x: word1) s1.append(x);
        for(string x: word2) s2.append(x);
        n1 =  s1.length(), n2 = s2.length();
        
        if(n1 == n2){
            for(int i = 0; i < n1; i++){
                if(s1[i] != s2[i]) return false;
            }
        }
        else return false;
        
        return true;
    }
};