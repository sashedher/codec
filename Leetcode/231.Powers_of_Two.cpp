// https://leetcode.com/problems/power-of-two/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<sizeof(int)*8+1> x(n);
        if(x.count()==1) return true;
        else return false;
        
    }
};