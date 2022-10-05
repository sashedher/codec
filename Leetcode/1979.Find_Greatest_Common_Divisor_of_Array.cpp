// https://leetcode.com/problems/find-greatest-common-divisor-of-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        else return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int x= *max_element(nums.begin(),nums.end());
        int y= *min_element(nums.begin(),nums.end());
            
        return gcd(x,y);
    }
};