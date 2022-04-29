// https://leetcode.com/problems/spiral-matrix-ii


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n,vector<int>(n,0));
        
        int l=0;
        int r=n-1;
        int u=0;
        int d=n-1;
        int c=1;
        while(l<=r && u<=d){
            
            for(int i=l;i<=r;i++) res[u][i]=c++;
            u++;
            if(u>d) break;
            
            for(int i=u;i<=d;i++) res[i][r]=c++;
            r--;
            if(r<l) break;
            
            for(int i=r;i>=l;i--) res[d][i]=c++;
            d--;
            if(d<u) break;
            
            for(int i=d;i>=u;i--) res[i][l]=c++;
            l++;
            if(l>r) break;
        }
       return res; 
    
    }
};