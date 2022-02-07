// https://www.interviewbit.com/problems/set-matrix-zeros/
#include<bits/stdc++.h>
using namespace std;

class Solution{
   void setZeroes(vector<vector<int> > &A) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        set<int> row,col;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[i].size();j++){
                if(A[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it=row.begin();it!=row.end();it++){
            int r=*it;
            for(int j=0;j<A[r].size();j++){
                A[r][j]=0;
            }
        }
        for(auto it=col.begin();it!=col.end();it++){
            int c=*it;
            for(int j=0;j<A.size();j++){
                A[j][c]=0;
            }
        }

    }
};

