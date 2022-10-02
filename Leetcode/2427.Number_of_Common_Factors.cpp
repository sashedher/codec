// https://leetcode.com/problems/number-of-common-factors/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        if(a==0) return b;
        else return gcd(b%a, a);
    }
    
    int commonFactors(int a, int b) {
        int res = gcd(a,b);
        int count=0;
        for(int i=1;i<=res;i++){
            if(res%i==0) count++;
        }
        
        return count;
    }
};