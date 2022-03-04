// https://leetcode.com/problems/champagne-tower/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101,vector<double>(101,0.0));
        t[0][0]=(double)poured;
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
               
                if(t[i][j]>=1){                                     //if glass is filled
                    double q= (double) (t[i][j]-1.0)/2;             //split into half   
                    t[i][j]=1;                                      //make that glass as full
                    t[i+1][j]  +=q;                                 //fill below glasses with remaining into equal halves ->q   
                    t[i+1][j+1]+=q;
                }
            }
        }
        return t[query_row][query_glass];
    }
};