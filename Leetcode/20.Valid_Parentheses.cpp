// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0;i<s.length();i++){
            if(p.empty() && (s[i]==')' || s[i]=='}' || s[i]==']')) return false;
            
            else if(s[i]=='(' || s[i]=='{' || s[i]=='[') p.push(s[i]);
            else if( (s[i]==')' && p.top()=='(')  ||  (s[i]=='}' && p.top()=='{') || (s[i]==']' && p.top()=='[')) p.pop();
            else return false;
        }
        return p.empty();
    }
};