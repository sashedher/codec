// https://leetcode.com/problems/bitwise-xor-of-all-pairings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2= nums2.size();
        int res=0;
        if(n1%2){
            for(int x:nums2) res=res^x;
        }
        if(n2%2){
            for(int x:nums1) res=res^x;
        }
        return res;
    }
};