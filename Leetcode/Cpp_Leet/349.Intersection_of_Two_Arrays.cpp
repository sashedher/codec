// https://leetcode.com/problems/intersection-of-two-arrays

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        set<int> s;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) s.insert(nums1[i]);
            }
        }
        return {s.begin(),s.end()};
    }
};