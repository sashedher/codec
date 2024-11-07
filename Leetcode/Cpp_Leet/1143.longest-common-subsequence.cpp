/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
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

