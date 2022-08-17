// https://leetcode.com/problems/longest-word-in-dictionary/

#include<bits/stdc++.h>
using namespace std;

struct node{
    node* links[26]={NULL};
    bool isEnd=false;
};

class Trie{
private: node* root;
public:
    Trie(){
        root=new node();
    }
    
    void insert(string word){
        int n= word.length();
        node* temp=root;
        
        for(int i=0;i<n;i++){
            if(!temp->links[word[i]-'a']) temp->links[word[i]-'a']=new node();
            
            temp=temp->links[word[i]-'a'];
        }
        
        temp->isEnd=true;
    }
    bool search(string word){
        int n= word.length();
        node* temp=root;
        
        for(int i=0;i<n;i++){
            if(!temp->links[word[i]-'a']) return false; 
            temp=temp->links[word[i]-'a'];
        }
        
       return temp->isEnd;
    }
        
        
};

class Solution {

public:
    string longestWord(vector<string>& words) {
        Trie tr;
        int n=words.size();
        string res="";
        for(string x:words) tr.insert(x);
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<words[i].length();j++){
                temp=temp+words[i][j];
                if(tr.search(temp)){
                    if(temp.length()==res.length()){
                        if(temp<res) res=temp;
                    }
                    else if( temp.length() > res.length() ) res=temp;
                }
                else break;
               
            }
            
            
        }
        
        return res;
    }
};