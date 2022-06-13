// https://leetcode.com/problems/valid-perfect-square/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,h=num;
        while(l<=h){
            long long int m=l+(h-l)/2,m2=1;
            m2=m*m;
            if(m2==num) return true;
            else if(m2>num) h=m-1;
            else l=m+1;
            
        }
        
        return false;
    }
    
};