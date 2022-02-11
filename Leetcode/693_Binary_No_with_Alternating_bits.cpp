// https://leetcode.com/problems/binary-number-with-alternating-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long int cr=1,i=0;
        while(cr<=n){
            if(cr==n) return true;
            else if(i%2==0)  cr=cr*2;
            else{
                cr=cr*2+1;
            }
            i++;
        }
        return false;
    }
};