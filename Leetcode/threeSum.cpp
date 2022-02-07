// https://leetcode.com/problems/3sum/ -not done (time limit exceed)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        multimap<int,int> op;
        int k=0;
        for(int i=0;i<nums.size();i++){
            op.insert({nums[i],i});
        }
        set<multiset<int>> s;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                multiset<int> t;
                auto itr=op.upper_bound(-nums[i]-nums[j]);
                    *itr--;
                if(itr->second+1 < op.size() && j < itr->second ){
                   t.insert({nums[i],nums[j],nums[itr->second]});
                   s.insert(t); 
                }     
            }
        }
        vector<vector<int>> ans(0);
        for(auto itr=s.begin();itr!=s.end();itr++){
            vector<int> t;
            for(auto itr1=itr->begin();itr1!=itr->end();itr1++){
                t.push_back(*itr1);
            }
            ans.push_back(t);    
        }

        return ans;
    }
};