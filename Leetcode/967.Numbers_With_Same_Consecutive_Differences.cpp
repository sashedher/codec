// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BackTrack(int x,int ds,int k,int n,set<int> & res){
        if(ds==n){
            res.insert(x);
            return;
        }
        
        int t=x%10;
        if(t+k<10) BackTrack(x*10+k+t,ds+1,k,n,res);
        if(t-k>=0) BackTrack(x*10+t-k,ds+1,k,n,res);

            
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> res;
        for(int i=1;i<=9;i++) BackTrack(i,1,k,n,res);
        
        return {res.begin(),res.end()};
    }
};