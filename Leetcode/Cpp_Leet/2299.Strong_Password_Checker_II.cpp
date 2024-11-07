// https://leetcode.com/problems/strong-password-checker-ii

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        int n=pass.length();
        if(n<8) return false;
        for(int i=0;i<n-1;i++){
            if(pass[i]==pass[i+1]) return false;
        }
        set<char> sp({'!','@','#','$','%','^','&','*','(',')','-','+'});
        int l=0,u=0,d=0,s=0;
        for(int i=0;i<n;i++){
            if(pass[i]<=57 && pass[i]>=48) d=1;
            if(pass[i]<=122 && pass[i]>=97) l=1;
            if(pass[i]<=90 && pass[i]>=65) u=1;
            if(sp.find(pass[i])!=sp.end()) s=1;
        }
        if(d==0 || l==0 || u==0 || s==0) return false;
        
        return true;

        //using regular Expression?
        // return password.matches("(?=.{8,})(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!@#$%^&*()+-])(?!.*(.)\\1).*");
    }
};