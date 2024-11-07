// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res;
        stack<int> st;
        int n=s.length(),c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
                st.push(i);
            }
            else if(s[i]==')'){
                if(c>0){
                 c--;
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
        
        
    }
};