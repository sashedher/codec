// https://leetcode.com/problems/permutation-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string ans="",res="";
        for(char c='1';c<=n+'0';c++){
            ans=ans+c;
        }
        vector<int> fact={1,1,2,6,24,120,720,5040,40320,362880};
        k--;
        int i=n;
        while(i>1){
            int x=k/fact[i-1];
            res.push_back(ans[x]);
            k=k%fact[i-1];
            ans.erase(x,1);
            i--;
        }
        res.push_back(ans[0]);
        
        return res;
    }
};