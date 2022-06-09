 
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    int solve(vector<int> &A) {
        int sm=0,n=A.size();
        for(int x:A){
            sm+=x;
        }
        // vector<vector<bool>> t(A.size()+1,vector<bool>(sm+1,false));
        // for(int i=0;i<=A.size();i++){
        //     t[i][0]=true;
        // }
        // for(int i=1;i<=A.size();i++){
        //     for(int j=1;j<=sm;j++){
        //         if(A[i-1]<=j){
        //             t[i][j]=t[i-1][j] || t[i-1][j-A[i-1]];
        //         }
        //         else t[i][j]=t[i-1][j];
        //     }
        // }

        vector<bool> curr(sm+1,false);
        vector<bool> prev(sm+1,false);
        curr[0]=true;
        prev[0]=true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sm;j++){
                if(A[i-1]<=j)
                    curr[j]= prev[j-A[i-1]] || prev[j];
                else
                    curr[j]=prev[j];
            }
            prev.clear();
            prev=curr;
        }

        int mn=INT_MAX;
        // vector<int> res;
        int x=0;
        for(int i=sm/2;i>=0;i++){
            if(curr[i]==true){
                x=i;
                break;
            }
        }
        return abs(sm-2*x);
    }
};