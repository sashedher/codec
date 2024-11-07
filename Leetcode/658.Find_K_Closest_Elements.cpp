// https://leetcode.com/problems/find-k-closest-elements/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        int n=arr.size();
        vector<int> res;
        
        for(int i=0;i<n;i++){
            int a= abs(x-arr[i]);
            q.push({a,arr[i]});
        }
        while(k--){
            int p=q.top().second;
            res.push_back(p);
            q.pop();
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};