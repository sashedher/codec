//O(n^3)-Brute force Approach

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(const vector<int>& A) {
    int i,j,k,sum=INT_MIN;
    int nsum=0;
    int l=A.size();
    for(i=0;i<l;i++){
        for(j=l-1;j>=i;j--){
            nsum=0;
            for(k=i;k<=j;k++){
                nsum=nsum+A[k];
            }
            if(nsum>sum){
                sum=nsum;
            }
        }
    }
    return sum;
}

int main(){
    cout<<"hello World\n";
    vector<int> A;
    A={4,-1,2,1,7,-3};
    cout<<maxSubArray(A)<<"\n";
    return 0;

}