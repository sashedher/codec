// https://leetcode.com/problems/break-a-palindrome/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palin) {
        int n=palin.size();
        if(n==1) return "";
        for(int i=0;i<n/2;i++){
            if(palin[i]!='a'){
                palin[i]= 'a';
                return palin;
            }
        }
        if(palin[n-1]!='a')   palin[n-1]='a';
        else palin[n-1]=palin[n-1]+1;
        return palin;
    }
};