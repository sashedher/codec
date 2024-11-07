// https://leetcode.com/problems/zigzag-conversion/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        int n=s.length();
        int i=0,flg=0;
        while(i<n){
            if(flg==0){
                int j=0;
                while(i<n && j<numRows){
                    ans[j].push_back(s[i]);
                    j++;
                    i++;
                }
                flg=1-flg;
            }
            else{
                int j=numRows-2;
                while(i<n && j>0){
                    ans[j].push_back(s[i]);
                    j--;
                    i++;
                }
                flg=1-flg;
                
            }
            
        }
        string res="";
        for(int i=0;i<numRows;i++){
            res=res+ans[i];
        }
        return res;
    }
};