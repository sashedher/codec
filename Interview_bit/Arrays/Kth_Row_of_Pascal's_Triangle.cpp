// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    vector<int> getRow(int n) {
        vector<vector<int>> pt;
            
            pt.push_back({1});
            if(n==0) return pt[0];

            for(int i=1;i<=n;i++){
                pt.push_back({});
                for(int j=0;j<=pt[i-1].size();j++){
                    if(j==0 || j==pt[i-1].size()){
                        pt[i].push_back(1);
                    }
                    else pt[i].push_back(pt[i-1][j-1]+pt[i-1][j]);
                }
            }
            return pt[n];
    }

};
