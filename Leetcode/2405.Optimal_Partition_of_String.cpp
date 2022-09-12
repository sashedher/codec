// https://leetcode.com/problems/optimal-partition-of-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n=s.length(),res=1;
        set<char> se;
        
        for(int i=0;i<n;i++){
            if(se.find(s[i])==se.end()){
                se.insert(s[i]);
            }
            else{
                res++;
                se.clear();
                se.insert(s[i]);
                
            }
        }
    
        return res;
    }
};