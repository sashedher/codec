// https://leetcode.com/problems/n-th-tribonacci-number/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        vector<int> v{vector<int>(38,-1)};
    int tribonacci(int n) {
        if(n==0 || n==1) return n;
        if(n==2) return 1;
        if(v[n]!= -1) return v[n];
        else return v[n]=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);        
    }
};