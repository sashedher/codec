// https://leetcode.com/problems/fibonacci-number/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> v{vector<int>(31,-1)};
    int fib(int n) {
        if(n==0 || n==1) return n;
        if(v[n]!= -1) return v[n];
        else return v[n]=fib(n-1)+fib(n-2);
        
    }
};