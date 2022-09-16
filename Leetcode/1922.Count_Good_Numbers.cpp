// https://leetcode.com/problems/count-good-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
   long powr(int x,long y){
        long  res;
        if(y==0) return 1;
        res=powr(x,y/2);
        if(y%2==0) return (res*res)%mod;
        else return (x*res*res)%mod;
    }
    int countGoodNumbers(long long n) {
        long  a,b;
        a=powr(4,n/2);
        if(n%2) b=powr(5,n/2+1);
        else b=powr(5,n/2);
        long c= a*b %mod;
        
        return (int)c;
        
    }
};