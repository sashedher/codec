// https://leetcode.com/problems/count-and-say/

#include<bits/stdc++.h>
using namespace std;
                            
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string r=countAndSay(n-1),res="";
        int n1=r.length(),count=1;
        r=r+' ';
        char s=r[0];
        for(int i=1;i<=n1;i++){
            if(r[i]==s) count++;
            else{
                res=res+ to_string(count);
                res=res+ s;
                s=r[i];
                count=1;
            }
        }
         
        return res;
    }
};