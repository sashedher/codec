// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int m=q.size(), n= nums.size();
        int sum=0;
        vector<int> res;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) sum+=nums[i];
        }
        
        for(int i=0;i<m;i++){
            if(nums[q[i][1]]%2==0){                     // for even variable remove current sum
                sum=sum-nums[q[i][1]];
            }
            nums[q[i][1]]= nums[q[i][1]]+q[i][0];
            if(nums[q[i][1]]%2==0){                     // for after adding val from query  if its even add to sum 
                sum=sum+nums[q[i][1]];
            }
            res.push_back(sum);                         // finally for every query push sum to res
        }
        
        return res;
    }
};