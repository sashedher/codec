// https://leetcode.com/problems/simplify-path/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int n=path.length();
        for(int i=0;i<n;i++){
            string temp;
            if(path[i]=='/') continue;
            while(i<n && path[i]!='/'){
                temp+=path[i];
                i++;
                
            }
            if(temp==".") continue;
            if(temp==".." ) {
                if(!s.empty()) s.pop();
            }
            else s.push(temp);
            
        }
        if(s.empty()) return "/";
        string res;
        while(!s.empty()){
            res='/'+s.top()+res;
            s.pop();
        }
        return res;
    }
};