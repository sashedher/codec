// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<3) return nums.size();
        
        for(auto i=nums.begin();i<nums.end()-2;){
            if( (*i==*(i+1)) && (*i==*(i+2)) ){
                nums.erase(i);
                
            }
            else i++;
        }
        return nums.size();
        
    }
};