// https://www.interviewbit.com/problems/maximum-unsorted-subarray/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    vector<int> subUnsort(vector<int> &A) {
        int l=A.size(),r=0,mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<A.size();i++){                    
            if(A[i]<mx) r=i;                            //update r only when A[i] is less than maxi-ele still found
            mx=max(mx,A[i]);    
        }
        for(int i=A.size()-1;i>=0;i--){
            if(A[i]>mn) l=i;                           //update l only when A[i] is more than mini-ele still found
            mn=min(mn,A[i]);
        }
        
        if(l==A.size()) return {-1};
        else return {l,r};
    }


};