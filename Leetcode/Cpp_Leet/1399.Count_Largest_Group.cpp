// https://leetcode.com/problems/count-largest-group/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int sumDig(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        
        return sum;
    }
    
    
    int countLargestGroup(int n) {
        map<int,int> mp;
        int size=INT_MIN,res=0;
        
        for(int i=1;i<=n;i++){
            int sm=sumDig(i);
            mp[sm]++;
            size=max(size,mp[sm]);
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            // cout<<it->first<<" "<<it->second<<endl;
            if(it->second==size) res++;
        }
        
        return res;
    }
};