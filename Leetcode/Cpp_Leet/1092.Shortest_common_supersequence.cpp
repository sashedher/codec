// https://leetcode.com/problems/shortest-common-supersequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        vector<vector<int>> t(t1.length()+1,vector<int>(t2.length()+1,0));
        for(int i=1;i<=t1.length();i++){
            for(int j=1;j<=t2.length();j++){
                if(t1[i-1]==t2[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        int i=t1.length();
        int j=t2.length();
        string r;
        while(i>0 && j>0){
            if(t1[i-1]==t2[j-1]){
                r.push_back(t1[i-1]);
                i--;
                j--;
            }
            else if( t[i-1][j] > t[i][j-1] ) {
                i--;
                r.push_back(t1[i]);
            }
            else{
                j--;
                r.push_back(t2[j]);
            }
        }
        while(i>0) {r.push_back(t1[i-1]);i--;}
        while(j>0) {r.push_back(t2[j-1]);j--;}
        reverse(r.begin(),r.end());
        return r;
    }
};