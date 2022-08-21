// https://leetcode.com/problems/bag-of-tokens/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i=0,j=tokens.size()-1;
        int score=0,res=0;
        sort(tokens.begin(),tokens.end());
        
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                i++;
                score++;
                res=max(res,score);
            }
            else if(score>0){
                power+=tokens[j];
                j--;
                score--;
            }
            else break;
        }
        
        return res;
    }
};