// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

struct node{
        node* link[26];
        int cw=0,cp=0;
        bool containsNode(char i){
            return link[i-'a']!= NULL;
        }
        void putNode(char i, node* t){
            link[i-'a']=t;
        }
        node* getNode(char i){
            return link[i-'a'];
        }    
    };
class Trie{
    private: node* root;
    public:

    Trie(){
            root=new node();        
    }

    void insert(string &word){
        node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(word[i]) ){
                temp->putNode(word[i],new node());
            }
            temp=temp->getNode(word[i]);
            temp->cp = temp->cp+1;
        }
        temp->cw=temp->cw+1;
    }

    int countWordsEqualTo(string &word){
        node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(word[i]) ){
                return 0;
            }
            temp=temp->getNode(word[i]);
        
        }
        return temp->cw;
    }

    int countWordsStartingWith(string &prefix){
        node* temp=root;
        int n=prefix.length();
        for(int i=0;i<n;i++){
            if( !temp->containsNode(prefix[i]) ){
                return 0;
            }
            temp=temp->getNode(prefix[i]);
        
        }
        return temp->cp;
    }

    void erase(string &word){
        node* temp=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            
            temp=temp->getNode(word[i]);
            temp->cp=temp->cp-1;
        }
        temp->cw = temp->cw-1;
    }
};
