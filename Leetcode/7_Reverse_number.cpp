// https://leetcode.com/problems/reverse-integer/
#include<bits/stdc++.h>
using namespace std;

#define mx 2147483647
#define mn -2147483648
class Solution {
public:
    int reverse(int x) {
       int rev=0,r=0,t;
        t=abs(x);
        
      
        while(t>0){
            r=t%10;
            if((long)rev*10<=mx) rev=rev*10+r;
            else return 0;
            t/=10;
            
        }
        if(x>=0)  return rev;
        else return -rev;
    }
};