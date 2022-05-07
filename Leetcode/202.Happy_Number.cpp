// https://leetcode.com/problems/happy-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> m;
        int r=0,s=0,t=n;
        while(t>0){
            s=s+(t%10)*(t%10);
            t=t/10;
                if(t==0){
                    if(s==1) return true;
                    else{
                        t=s;
                        if(m.find(s)!=m.end()) break;
                        m.insert(s);
                        s=0;
                    }
                } 
        }
        return false;
        
    }
};