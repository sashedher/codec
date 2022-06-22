// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int c=0;
        while(num>0){
            if(num%2) num--;
            else num/=2;
            c++;
        }
        return c;
    }
};