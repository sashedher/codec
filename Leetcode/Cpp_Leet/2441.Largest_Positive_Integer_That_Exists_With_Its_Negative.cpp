https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int res=-1;
        for( set<int>::reverse_iterator rit=s.rbegin();rit!=s.rend();rit++){
            if(s.find(-*rit)!=s.end()){
                    return *rit;                
            }
        }
        return res;
    }
};