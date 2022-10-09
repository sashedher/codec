// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=INT_MIN,n= heights.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
               int  rg=i,lg=0,h=heights[st.top()];
                st.pop();
                if(!st.empty()) lg=st.top()+1;
                
                res=max(res, (rg-lg)*h);
            } 
            st.push(i);
        }
        while(!st.empty()){
           int h=heights[st.top()],rg=n,lg=0;
            st.pop();
            if(!st.empty()) lg=st.top()+1;
            
            res=max(res, (rg-lg)*h);
            
        } 
        return res;
        
        
    }
};