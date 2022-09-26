// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(),nums.end());
        int x,y;
        x=pq.top();
        pq.pop();
        y=pq.top();
        return (x-1)*(y-1);
    }
};