// https://leetcode.com/problems/powx-n/
 
 
#include<bits/stdc++.h>
using namespace std;

double i=1.0;
class Solution {
public:
    double myPow(double x, int n) {
        if(n>0) return powr(x,n);
        else return i/powr(x,abs(n));
        
    }
    double powr(double x,int n){
        double res;
        if(n==0) return i;
        res=powr(x,n/2);
        res=res*res;
        if(n%2==0) return res;
        else return x*res;
    }
};