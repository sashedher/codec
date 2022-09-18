// https://leetcode.com/problems/smallest-even-multiple/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int smallestEvenMultiple(int n) {
        if(n%2) return 2*n;
        else return n;
    }
};