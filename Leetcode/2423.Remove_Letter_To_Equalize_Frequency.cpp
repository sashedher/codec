// https://leetcode.com/problems/remove-letter-to-equalize-frequency/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int> &v){
        int x=0,i=0;
        for(;i<26;i++){
            if(v[i]>0){
                x=v[i];
                break;
            }
        }
        for(int j=i;j<26;j++) if(v[j]!=0 && v[j]!=x) return false;
        return true;
    }

    bool equalFrequency(string word) {
        vector<int> freq(26,0);
        int n= word.length();
        
        for(int i=0; i<n;i++){
            freq[word[i]-'a']++;
        }

        for(int i=0;i<n;i++){
                
            freq[word[i]-'a']--;
            if(solve(freq)) return true;
            freq[word[i]-'a']++;
        }
        return false;
    }
};