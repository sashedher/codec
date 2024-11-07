// https://leetcode.com/problems/strictly-palindromic-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPalin(vector<int> nums){
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]!=nums[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        int t=n,i=2;
        
        while(i<=t-2){
            vector<int> res;
            int tp=n;
            while(tp>0){
                res.push_back(tp%i);
                tp/=i;
            }
            if(!checkPalin(res)) return false;
            i++;
        }
        return true;
    }
};