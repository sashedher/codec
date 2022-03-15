//  https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2) return nums.size();
        
        for(auto i=nums.begin();i<nums.end()-1;){
            if(*i==*(i+1)){
                nums.erase(i);
                
            }
            else i++;
        }
        return nums.size();
    }
};