// https://leetcode.com/problems/counting-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            bitset<100000> x(i);
            res.push_back(x.count());
        }
        return res;
    }
};