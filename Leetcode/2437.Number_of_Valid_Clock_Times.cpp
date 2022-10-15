// https://leetcode.com/problems/number-of-valid-clock-times/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTime(string time) {
        int h1=1,h2=1,m1=1,m2=1;
        int t1,t2,t3,t4;
        if(time[0]=='?'){
            if(time[1]!='?'){
                int x=time[1]-'0';
                h1=x<4?3:2;
            }
            else{
                h1=3;
            }
        }
        if(time[1]=='?'){
            if(time[0]!='?'){
                int x=time[0]-'0';
                h2=x<2?10:4;
            }
            else{
                h2=8;
            }
        }
        if(time[3]=='?')    m1=6;
        if(time[4]=='?')    m2=10;
        // cout<<h1<<" "<<h2<<" "<<m1<<" "<<m2<<endl;
       return h1*h2*m1*m2;
    }
};