// https://leetcode.com/problems/sort-the-people//

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(pair<int,string> &a, pair<int,string> &b){
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> pp;
        int n= names.size();
        
        for(int i=0;i<n;i++){
            pp.push_back({heights[i],names[i]});
        }
        sort(pp.begin(),pp.end(),compare);
        
        vector<string> res;
        for(int i=0;i<n;i++){
            res.push_back(pp[i].second);
        }
        
        return res;
    }
};