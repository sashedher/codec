// https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

#include<bits/stdc++.h>
using namespace std;

struct node{
        node* link[26];
        int cp=0;
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
        
    }



    int countWordsStartingWith(string &prefix){
        node* temp=root;
        int n=prefix.length();
        int count=0;
        for(int i=0;i<n;i++){
            if( !temp->containsNode(prefix[i]) ){
                return 0;
            }
            
            temp=temp->getNode(prefix[i]);
            count=count+temp->cp;
        }
        return count;
    }

 
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie tr;
        int n=words.size();
        vector<int> res(n,0);
        
        for(int i=0;i<n;i++)    tr.insert(words[i]);
        
        
        for(int i=0;i<n;i++)    res[i]=tr.countWordsStartingWith(words[i]);
        
        
        return res;
    }
};