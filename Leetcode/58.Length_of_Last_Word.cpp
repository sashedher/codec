// https://leetcode.com/problems/length-of-last-word/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int f=0,l=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==32 && f==0) continue;
            else{
                f=1;
                if(s[i]==32) break;
                l++;
            }
        }
        return l;
        
    }
};