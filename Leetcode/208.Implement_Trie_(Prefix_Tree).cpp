// https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;

// create a structure to trie
struct node{
        node* link[26];
        bool flg=false;
        bool containsNode(char i){
            return link[i-'a']!= NULL;
        }
        
        void putNode(char i, node* t){
            link[i-'a']=t;
            
        }
        
        node* getNode(char i){
            return link[i-'a'];
        }
        void putEnd(){
            flg=true;
        }
        
        bool getEnd(){
            return flg;
        }
    
    };

class Trie {
    private: struct node* root;
public:
    
    Trie() {
        root= new node();
    }
    
    void insert(string word) {
        node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(word[i]) ){
                temp->putNode(word[i],new node());
            }
            temp=temp->getNode(word[i]);
        }
        temp->putEnd();
    }
    
    bool search(string word) {
        node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(word[i]) ){
                return false;
            }
            temp=temp->getNode(word[i]);
        
        }
        return temp->getEnd();
    }
    
    bool startsWith(string prefix) {
        node* temp=root;
        int n=prefix.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(prefix[i]) ){
                return false;
            }
            temp=temp->getNode(prefix[i]);
        
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */