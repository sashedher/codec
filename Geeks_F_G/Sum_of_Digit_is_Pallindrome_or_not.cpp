// https://practice.geeksforgeeks.org/problems/sum-of-digit-is-pallindrome-or-not2751/1
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    int isDigitSumPalindrome(int N) {
        
        // code here
        int s=0,rev=0,t;
        while(N>0){
            s=s+N%10;
            N/=10;
        }
        t=s;
        while(t>0){
            rev=rev*10+t%10;
            t/=10;
        }
        if(s==rev) return 1;
        else return 0;
        
    }
 
};