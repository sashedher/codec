// https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

struct node{
        node* link[26];
       
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


int countDistinctSubstrings(string &s){
    node* root=new node();
    int count=0,n=s.length();
    for(int i=0;i<n;i++){
        node* temp=root;
        for(int j=i;j<n;j++){
            if(!temp->containsNode(s[j])){
                temp->putNode(s[j],new node());
                count++;
            }
            temp=temp->getNode(s[j]);
        }
    }
    
    return count+1;
}