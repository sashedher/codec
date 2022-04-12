// https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        set<int> row, col;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                if (A[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                if (row.find(i)!=row.end() || col.find(j)!=col.end())
                {
                    A[i][j]=0;
                }
            }
        }       
    }
};