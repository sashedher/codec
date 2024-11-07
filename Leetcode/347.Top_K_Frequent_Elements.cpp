// https://leetcode.com/problems/top-k-frequent-elements/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
            const noexcept
        {
            return a.second < b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> fq;
        
        for(int x:nums){
            if(fq.find(x)==fq.end()) fq[x]=1;
            else fq[x]+=1;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,myComp > q(fq.begin(),fq.end());
        vector<int> res;
        while(k--){
            res.push_back(q.top().first);
            q.pop();
        }
        
        return res;
    }
};