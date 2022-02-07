// https://leetcode.com/problems/3sum/ -not done (time limit exceed)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        multimap<int,int> op;
        vector<vector<int>> res(0);
        int k=0;
        for(int i=0;i<nums.size();i++){
            op.insert({nums[i],i});
        }
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                auto itr=op.upper_bound(-nums[i]-nums[j]);
                    *itr--;
                if(itr->second+1 < op.size() && j < itr->second ){
                    
               res.push_back({nums[i],nums[j],nums[itr->second]});
                k++;    
            }
                
            }
            
        }
        set<set<int>> s;
        for(auto itr=res.begin();itr!=res.end();itr++){
            set<int> t;
            for(auto itr1=itr->begin();itr1!=itr->end();itr1++){
                t.insert(*itr1);
            }
            s.insert(t);    
        }
        // res.erase(res.begin(),res.end());
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