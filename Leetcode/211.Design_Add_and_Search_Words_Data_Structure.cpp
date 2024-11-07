

#include<bits/stdc++.h>
using namespace std;

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

class WordDictionary {
    
private: struct node* root;

public:
    WordDictionary() {
         root= new node();
    }
    
    void addWord(string word) {
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
        return search(word,0,root);
    }


    bool search(string word,int i,node* dict){                  // recursive method for '.' check all links of refernce node
        if(i==word.length()) return dict->flg;
        if(word[i]!='.'){
            return dict->getNode(word[i]) && search(word,i+1,dict->getNode(word[i]));
        }
        else{
            for(int j=0;j<26;j++){
                if(dict->link[j] && search(word,i+1,dict->link[j])) return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */