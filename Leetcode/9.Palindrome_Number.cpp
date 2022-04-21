// https://leetcode.com/problems/palindrome-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else{
            long long int rev=0,r=0,t;
            t=x;
            while(t>0){
                r=t%10;
                rev=rev*10+r;
                t/=10;

            }
            if(x==rev)  return true;
            else return false;
        }
    }
};