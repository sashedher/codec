// https://leetcode.com/problems/power-of-four/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1){
            if(n%4!=0) return false;
            n/=4;
        }
        
        return n==1;
        
    }
};