// https://leetcode.com/problems/ugly-number

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        int flag=1;
        if(n<0) return 0;
        while(n>1 && flag==1){
            flag=0;
            if(n%2==0){
                n/=2;
                flag=1;
            }
            if(n%3==0){
                n/=3;
                flag=1;
            }
            if(n%5==0){
                n/=5;
                flag=1;
            }
        }
        return n==1;
    }
};