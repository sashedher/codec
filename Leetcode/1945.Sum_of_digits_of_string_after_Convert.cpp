// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        int n=0,sm=0;
        for(int i=0;i<s.length();i++){
            n=s[i]-96;
            while(n>0){
                sm=sm+n%10;
                n/=10;
            }
        }
        n=0;
        while(--k){
            n=0;
            while(sm>0){
                n=n+sm%10;
                sm/=10;
            }
            sm=n;
        }
        return sm;
        
    }
};