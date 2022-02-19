 
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    int solve(vector<int> &A) {
        int sm=0;
        for(int x:A){
            sm+=x;
        }
        vector<vector<bool>> t(A.size()+1,vector<bool>(sm+1,false));
        for(int i=0;i<=A.size();i++){
            t[i][0]=true;
        }
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=sm;j++){
                if(A[i-1]<=j){
                    t[i][j]=t[i-1][j] || t[i-1][j-A[i-1]];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        int mn=INT_MAX;
        vector<int> res;
        for(int i=0;i<=sm/2;i++){
            if(t[A.size()][i]==true)    res.push_back(i);
        }
        for(int i=0;i<res.size();i++){
            mn = min(mn , abs(sm-2*res[i]) );
        }
        return mn;
    }
 

};