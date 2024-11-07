// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> fut,prev;
        for(int x:nums) prev[x]++;
        
        for(int x: nums){
            if(prev[x]==0) continue;
            
            if(fut[x-1]>0){
                prev[x]--;
                fut[x-1]--;
                fut[x]++;
            }
            else{
                if(prev[x+1]==0 || prev[x+2]==0) return false;
                prev[x]--;
                prev[x+1]--;
                prev[x+2]--;
                fut[x+2]++;
            }
        }
        return true;
    }
};
