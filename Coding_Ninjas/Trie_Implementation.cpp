// https://www.codingninjas.com/codestudio/problems/trie-implementation_1062581?leftPanelTab=0

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

TrieNode* root=new TrieNode();
//To insert a word into the Trie
void insert(string word) {
	TrieNode* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->children[word[i]-'a'] ){
                temp->children[word[i]-'a']=new TrieNode();
            }
            temp=temp->children[word[i]-'a'];
        }
        temp->isEnd=true;         
}

//Returns if the word is present in the Trie
bool search(string word){
       TrieNode* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->children[word[i]-'a'] ){
                return false;
            }
            temp=temp->children[word[i]-'a'];
        }
        return temp->isEnd;   
}   
