// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int i=m-1;
        while(i>=0){
            vector<int> tp;
            int p=i,q=0;
            for(;p<m && q<n;p++,q++){
                tp.push_back(mat[p][q]);
            }
            sort(tp.begin(),tp.end());
            p=i,q=0;
            for(int k=0;p<m && q<n;p++,q++){
                mat[p][q]=tp[k++];
                // cout<<"("<<p<<","<<q<<"), ";
            }
            // cout<<endl;
            i--;
        }
        int j=1;
        while(j<n){
            vector<int> tp;
            int p=0,q=j;
            for(;q<n&& p<m;p++,q++){
               tp.push_back(mat[p][q]);
            }
            sort(tp.begin(),tp.end());
            p=0,q=j;
            for(int k=0;q<n&& p<m;p++,q++){
                mat[p][q]=tp[k++];
                // cout<<"("<<p<<","<<q<<"), ";
            }
            // cout<<endl;
            
            j++;
        }
        return mat;
    }
};