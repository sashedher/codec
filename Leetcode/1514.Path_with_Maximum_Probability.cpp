//  https://leetcode.com/problems/path-with-maximum-probability/
 
#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<double>> A(n,vector<double>(n,0));
        
        for(int i=0;i<edges.size();i++){
            A[ edges[i][0] ] [ edges[i][1] ]=succProb[i];
            A[ edges[i][1] ] [ edges[i][0] ]=succProb[i];
            
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                
                    if(i!=j)    A[i][j]=max(  A[i][k] * A[k][j]  , A[i][j]   );
                }
            }
        }
        return A[start][end];
    }
};