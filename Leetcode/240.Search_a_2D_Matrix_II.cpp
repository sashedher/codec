// https://leetcode.com/problems/search-a-2d-matrix-ii

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool BinSer(vector<int> &mat,int target){
        int l=0,h=mat.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(mat[m]==target) return true;
            else if(mat[m]>target) h=m-1;
            else l=m+1;
            
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int l=0,h=n-1;
        while(l<=h){
            // int m=(l+h)/2;
            if(BinSer(matrix[l],target)) return true;
            // else if(matrix[m][0]>target)    h=m-1;
            // else if(matrix[m][0]<target)    l=m+1;
            l++;
        }
        return false;
        
    }
};