// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=INT_MIN,n= heights.size();
        vector<int> pse(n), nse(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
                if(st.empty()) pse[i]=0;
                else pse[i]= st.top()+1;
                st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
                if(st.empty()) nse[i]=n-1;
                else nse[i]= st.top()-1;
                st.push(i);
        }
        
        for(int i=0;i<n;i++){
            res=max(res,(nse[i]-pse[i]+1)*heights[i]);
        }
        return res;
        
        
    }
};