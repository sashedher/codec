// https://leetcode.com/problems/count-sorted-vowel-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count=0;
    void Backtrack(string s,int n,int index,string ans){
        if(ans.length()==n) {
            count++;
            cout<<ans<<" ";
            return;
        }
        for(int i=index;i<s.length();i++){
                ans.push_back(s[i]);
                Backtrack(s,n,i,ans);
                ans.pop_back();
            
        }
    }
        
        
        
    int countVowelStrings(int n) {
        Backtrack("aeiou",n,0,"");
        return count;
    }
};