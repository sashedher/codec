// https://www.codingninjas.com/codestudio/problems/trie-delete-operation_1062663?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }

};


TrieNode* deleteWord(TrieNode* root, string word) {
    TrieNode* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
             if(!temp->children[word[i]-'a']) return root;
            temp=temp->children[word[i]-'a'];
            
        }
        temp->isEnd = false;
        return root;
}

