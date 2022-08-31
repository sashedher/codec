// https://www.codingninjas.com/codestudio/problems/implement-trie_631356?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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
private:
    node*  root;
public:

    /** Initialize your data structure here. */
    Trie() {
         root=new node();
    }

    /** Inserts a word into the trie. */
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

    /** Returns if the word is in the trie. */
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

    /** Returns if there is any word in the trie that starts with the given prefix. */
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