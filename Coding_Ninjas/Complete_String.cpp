// https://www.codingninjas.com/codestudio/problems/complete-string_2687860?leftPanelTab=0

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
void insert(node* root, string word) {
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

string completeString(int n, vector<string> &a){
    node*  root;
    root=new node();
    string res="None";
    for(int i=0;i<a.size();i++){
        insert(root,a[i]);
    }
    int l=0;
    for(int i=0;i<a.size();i++){
        string s=a[i];
        node* temp=root;
        int c=0;
        for(int j=0;j<s.length();j++){
            temp=temp->getNode(s[j]);
            if(!temp->getEnd()) break;
            c++;
        }
        if(c==s.length()){
            if(c==l){
                if(s.compare(res)<0) res=s;
            }
            else if(c>l){
                res=s;
                l=c;
            } 
        }
    }
    return res;
}