// https://www.interviewbit.com/problems/balance-array/ 
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 

    int solve(vector<int> &A) {
        int n=A.size(),spele=0;
        // for(int i=0;i<n;i++){
        //     count=0;
        //     sum=0;
        //     for(int j=0;j<n;j++){
        //         if(i!=j){
        //             count++;
        //             if(count%2==0) sum+=A[j];
        //             else sum-=A[j];
        //         }
        //     }
        //     if(sum==0) spele+=1;
        // }
        // // cout<<spele;
        int s1=0,s2=0,s3=0,s4=0;
        for(int i=0;i<n;i++){
            if(i%2) s2+=A[i];
            else s1+=A[i];
        }
        for(int i=0;i<n;i++){
            if(i%2){
                s2-=A[i];
                if(s2+s4==s1+s3) spele++;
                s3+=A[i];
            }
            else{
                s1-=A[i];
                if(s2+s4==s1+s3) spele++;
                s4+=A[i];

            }
        }
        return spele;
    }

};