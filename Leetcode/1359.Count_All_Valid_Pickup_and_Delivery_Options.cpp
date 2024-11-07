//  https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long m=1000000007;
    int countOrders(int n) {
        long long f=1;
        for(int i=1;i<=n*2;i++){
            if(i%2==0)  f=( f*(i/2) ) % m;
            else        f=( f*i ) % m;
        }
        return f;
    }
};