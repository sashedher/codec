// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(const vector<int>& A) {
    int n=A.size();
    int maxsum=INT_MIN;


    int currsum=0;


    for(int i=0;i<n;i++){


    currsum=currsum+A[i];
    
    maxsum=max(maxsum,currsum);
    
    if(currsum<0) currsum=0;

    }


    return maxsum;
}

int main(){
    cout<<"hello World\n";
    vector<int> A;
    A={4,-1,2,1,7,-3};
    cout<<maxSubArray(A)<<"\n";
    return 0;

}