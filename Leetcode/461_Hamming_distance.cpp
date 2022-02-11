// https://leetcode.com/problems/hamming-distance/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z=x^y;
        int c=0;
        while(z>0){
            c=c+z%2;
            z=z/2;
        }
        return c;
        
    }
};