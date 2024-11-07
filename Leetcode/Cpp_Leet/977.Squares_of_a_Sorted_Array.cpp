// https://leetcode.com/problems/squares-of-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1,ind=j;
        vector<int> res(j+1);
        while(i<=j){
            int x= nums[i]*nums[i], y= nums[j]*nums[j];
            if( x > y){
                res[ind--]=x;
                i++;
            }
            else {
                res[ind--]=y;
                j--;
            }
        }
        return res;
    }
};
