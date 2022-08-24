// https://leetcode.com/problems/height-checker/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> res(heights.begin(),heights.end());
        int n=res.size(),c=0;
        sort(res.begin(),res.end());
        for(int i=0;i<n;i++){
            if(heights[i]!=res[i]) c++;
        }
        return c++;
    }
};