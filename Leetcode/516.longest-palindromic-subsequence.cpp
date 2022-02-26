/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int longestPalindromeSubseq(string t1) {
        string t2=t1;
        reverse(t2.begin(),t2.end()); 
        vector<vector<int>> t(t1.length()+1,vector<int>(t2.length()+1,0));
            for(int i=1;i<=t1.length();i++){
                for(int j=1;j<=t2.length();j++){
                    if(t1[i-1]==t2[j-1])
                        t[i][j]=1+t[i-1][j-1];
                    else t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
            return t[t1.length()][t2.length()];
        
    }
};
// @lc code=end

