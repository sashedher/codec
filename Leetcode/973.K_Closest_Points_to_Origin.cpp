// https://leetcode.com/problems/k-closest-points-to-origin/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<pair<int,int>,double> const& a,
        pair<pair<int,int>,double> const& b)
            const noexcept
        {
           return a.second > b.second;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<pair<int,int>,double>, vector<pair<pair<int,int>,double>>,myComp > q;
        for(auto x: points){
            double d=sqrt((double)pow(x[0],2)+pow(x[1],2));
            q.push({{x[0],x[1]},d});
        }
        vector<vector<int>> res(k,vector<int>(2));
        while(k--){
            res[k][0]=q.top().first.first;
            res[k][1]=q.top().first.second;
            q.pop();
        }
        return res;
    }
};