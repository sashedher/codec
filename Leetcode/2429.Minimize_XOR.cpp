// https://leetcode.com/problems/minimize-xor/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bitset<32> x1(num1),x2(num2),res;
        int c=x2.count();
        
        for(int i=31;i>=0;i--){
            if(x1[i]==1 && c>0){
                c--;
                res[i]=1;
            }
        }
        int i=0;
        while(c>0){
            if(x1[i]==0){
                res[i]=1;
                c--;
            }
            i++;
        }
        return (int)(res.to_ulong());
    }
};