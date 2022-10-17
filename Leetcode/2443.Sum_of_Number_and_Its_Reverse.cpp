// https://leetcode.com/problems/sum-of-number-and-its-reverse/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int n){
        int r=0;
        while(n>0){
            r=r*10+n%10;
            n/=10;
        }
        return r;
    }
    bool sumOfNumberAndReverse(int num) {
        int rnum=rev(num);
        int l=0, r=rnum;
        for(int i=0;i<=num;i++){
            int j=rev(i);
            if(i+j==num) return true;
        }
        return false;
    }
};