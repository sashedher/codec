// https://leetcode.com/problems/range-product-queries-of-powers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        bitset<32> bn(n);
        vector<int> v,res;
        for(int i=0;i<32;i++){
            if(bn[i]==1){
                v.push_back(pow(2,i));
            }
        }
        int sz=queries.size();
        for(int i=0;i<sz;i++){
            long t=1;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                t=t*v[j]%1000000007;
            }
            res.push_back(t);
        }
        return res;
    }
};