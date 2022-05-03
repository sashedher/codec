// https://leetcode.com/problems/valid-palindrome/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string rs,res;
        for(int i=0;i<s.length();i++){
            if(s[i]>64 && s[i]<91) rs.push_back(s[i]+32);
            else if(s[i]>96  && s[i]<123) rs.push_back(s[i]);
            else if(s[i]>47 && s[i]<58)  rs.push_back(s[i]);
            else continue;
                
        }
        res=rs;
        reverse(res.begin(),res.end());
        if(res==rs) return true;
        else return false;
    }
};