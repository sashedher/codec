// https://leetcode.com/problems/word-ladder/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> q;
        q.push({1,beginWord});
        set<string> st(wordList.begin(),wordList.end());
        st.insert(beginWord);
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            string x=it.second;
            int l=it.first;
            int n=x.length();
            if(x==endWord) return l;
            for(int i=0;i<n;i++){
                char tp=x[i];
                for(char j='a';j<='z';j++){
                    x[i]=j;
                    auto it=st.find(x);
                    if(it!=st.end()){
                        q.push({l+1,x});
                        st.erase(x);
                    }
                }
                x[i]=tp;
            }
            
        }
        return 0;
    }
};