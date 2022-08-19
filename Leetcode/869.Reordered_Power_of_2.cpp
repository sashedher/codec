// https://leetcode.com/problems/reordered-power-of-2/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDigits(int n){
        vector<int> res(10,0);
        while(n>0){
            res[n%10]++;
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> ans=countDigits(n);
        for(int i=0;i<32;i++){
            
            int count=0;
            vector<int> res=countDigits(1<<i);
            for(int i=0;i<10;i++){
                if(ans[i]==res[i]) count++;
            }
            if(count==10) return true;
        }
        return false;
        
    }
};