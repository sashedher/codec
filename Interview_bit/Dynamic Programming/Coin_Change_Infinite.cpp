//  https://www.interviewbit.com/problems/coin-sum-infinite/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    int Solution::coinchange2(vector<int> &A, int B) {
    vector<int> t(B+1,0);
    t[0]=1;
    for(int i=0;i<A.size();i++){
        for(int j=A[i];j<=B;j++){
             t[j]=(t[j] + t[j-A[i]]) % 1000007;
        }
    }
    return t[B] % 1000007;
}

};