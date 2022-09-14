// https://leetcode.com/problems/power-of-two/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return ( n&(n-1) )==0;
    }
};