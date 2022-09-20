// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int res=0;
        // cout<<x;
        while(x>0){
            res+=x%2;
            x/=2;
        }
        return res;
    }
};