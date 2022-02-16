// https://leetcode.com/problems/number-of-1-bits/ - Accepted

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> res(n);
        return res.count();
        
    }
};