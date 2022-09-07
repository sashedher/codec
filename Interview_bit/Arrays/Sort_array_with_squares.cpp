// https://www.interviewbit.com/problems/sort-array-with-squares/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    vector<int> solve(vector<int> &A) {
        int i=0,j=A.size()-1,ind=j;
        vector<int> res(j+1,0);
        
        while(i<=j){
            int x=A[i]*A[i];
            int y=A[j]*A[j];
            if(x>y){
                res[ind]=x;
                i++;
            }
            else{
                res[ind]=y;
                j--;
            }
            ind--;
        }
        return res;
    }

};