// https://leetcode.com/problems/maximal-rectangle/

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n= matrix[0].size(),result=INT_MIN;
        vector<int> dp(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') dp[j]+=1;
                else dp[j]=0;
            }
            result=max(result,largestRectangleArea(dp));
        }
        return result;
    }
};