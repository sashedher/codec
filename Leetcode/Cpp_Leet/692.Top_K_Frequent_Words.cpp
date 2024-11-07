// https://leetcode.com/problems/top-k-frequent-words/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<string, int> const& a,
        pair<string, int> const& b)
            const noexcept
        {
            if(a.second == b.second) return a.first > b.first ;
            else return a.second < b.second ;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> fq;
        
        for(auto x:words)   fq[x]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>,myComp > q(fq.begin(),fq.end());
        vector<string> res;
        while(k--){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};