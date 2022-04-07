// https://leetcode.com/problems/validate-stack-sequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int t,n1=pushed.size(),n2;
        n2=n1;
        
        stack<int> s1,s2;
        int i=0,j=0;
        for(;i<n1;i++){
            s1.push(pushed[i]);
            while(!s1.empty() && s1.top()==popped[j] && j<n1) {
                s1.pop();
                j++;
            }
        }
        if(j==n1) return true;
        else return false;
    }
};