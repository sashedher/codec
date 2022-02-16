//  https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public:
    int trailingZeroes(int N)
        {
            // Write Your Code here
            int  c=0;
            while(N>1){
            c=c+N/5;
            N/=5;
            }
            return c;
        } 
 
};