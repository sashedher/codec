// https://leetcode.com/problems/majority-element-ii/ -Accepted TC : O(n), SC : O(n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        multiset<int> mp(nums.begin(),nums.end());
        vector<int> res;
        set<int> ans(nums.begin(),nums.end());
        for(auto it=ans.begin();it!=ans.end();it++){
            if(mp.count(*it)>nums.size()/3){
                res.push_back(*it);
            }
        }
        return res;
    }
};

int main(){
    Solution ob;
    vector<int> nums={3};
    vector<int> it=ob.majorityElement(nums);
    cout<<"res vector size "<<it.size()<<endl;
    for (auto i = it.begin(); i !=it.end(); i++)    {
        /* code */
        cout<<*i<<" ";
    }
    cout<<endl;
    
    return 0;
}
