// https://leetcode.com/problems/container-with-most-water/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),res=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int x=min(height[i],height[j]),y=j-i;
            res=max(res,x*y);
            if(height[i]<height[j]) i++;
            else if(height[i]>height[j]) j--;
            else{
                i++;
                j--;
            }
        }
        return res;
    }
};