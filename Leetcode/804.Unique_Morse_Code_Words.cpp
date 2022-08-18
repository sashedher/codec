// https://leetcode.com/problems/unique-morse-code-words/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
         vector<string> dict={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> res;
        int n= words.size();
        for(int i=0;i<n;i++){
            int m= words[i].length();
            string ans="";
            for(int j=0;j<m;j++){
                ans=ans+dict[words[i][j]-'a'];
            }
            res.insert(ans);
        }
        
        // for(auto x:res) cout<<x<<endl;
        return res.size();
    }
};