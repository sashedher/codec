// https://leetcode.com/problems/move-zeroes/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        for(auto it=nums.begin();it!=nums.end();){
            if(*it==0) {
                nums.erase(it);
                c++;
            }
            else it++;
        }
        while(c--){
            nums.push_back(0);
        }
        
    }
};