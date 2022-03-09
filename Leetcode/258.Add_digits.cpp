// https://leetcode.com/problems/add-digits/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int s=0;
        while(num>0){
            s=s+num%10;
            num/=10;
        }
         int r=s%10 + (s/10)%10 + (s/100)%10 + (s/1000)%10;
        r=r%10+(r/10)%10;
        return r;
    }
};