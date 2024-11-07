// https://leetcode.com/problems/count-primes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int x){
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        
        for(int i=2;i*i<n;i++){
            if(prime[i] && !isPrime(i)) continue;
            for(int j=i*i;j<n;j=j+i){
                prime[j]=false;
            }
        }
        
        int c=0;
        for(int i=2;i<n;i++){
            if(prime[i])  c++;
            
        }
        return c;
    }
};