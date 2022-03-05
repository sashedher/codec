// https://leetcode.com/problems/delete-and-earn/submissions/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> f(10001,0);
        vector<int> t(10001,0);
        
        for(int i:nums)  f[i]++;
        t[1]=f[1];
        
        for(int i=2; i <10001;i++){
            t[i]=max(t[i-1] ,t[i-2]+i*f[i]);
        }
        
        return t[10000];
        
        
    }
};