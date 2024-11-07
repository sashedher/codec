// https://leetcode.com/problems/string-compression/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chrs) {
        int res=0,ind=0, n= chrs.size(), ct=1;
        char cr=chrs[0];
        chrs.push_back(' ');
        
        for(int i=1;i<=n;i++){
            if(chrs[i]==cr) ct++;
            else{
                chrs[ind++]=cr;
                res++;

                if(ct>1){
                    string x=to_string(ct);
                    for(char x1:x){
                        chrs[ind++]=x1;
                        res++;
                    }
                }
                
                cr=chrs[i];
                ct=1;
            }
        }
        return res;
    }
};