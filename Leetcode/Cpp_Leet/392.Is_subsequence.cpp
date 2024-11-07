// https://leetcode.com/problems/is-subsequence/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string t1, string t2) {
        int n1=t1.length(),n2=t2.length();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(t1[i]==t2[j]) i++;
            j++;
        }
        return i==n1;
    }
};