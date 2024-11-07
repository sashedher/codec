// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            set<int> r,c;
            for(int j=0;j<n;j++){
                r.insert(matrix[i][j]);
                c.insert(matrix[j][i]);
            }
            if(r.size()!= n) return false;
            if(c.size()!= n) return false;
        }
        
        return true;
        
    }
};