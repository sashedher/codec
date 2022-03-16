// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string t1){
		    vector<vector<int>> t(t1.length()+1,vector<int>(t1.length()+1,0));
            for(int i=1;i<=t1.length();i++){
                for(int j=1;j<=t1.length();j++){
                    if(t1[i-1]==t1[j-1] && i!=j)
                        t[i][j]=1+t[i-1][j-1];
                    else t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
            return t[t1.length()][t1.length()];
		}

};