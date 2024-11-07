// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countOdds(int low, int high) {
        low = low%2  ? low  : low+1;
        high= high%2 ? high : high-1;
        return (high-low)/2+1;
        
    }
};