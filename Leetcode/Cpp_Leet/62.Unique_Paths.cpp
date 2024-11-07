// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long  ans=1;
        for(int i=m;i<m+n-1;i++){
            ans*=i;
            ans/=(i-m+1);
        }
        
        return ans;
    }
};