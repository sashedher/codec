// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

#include<bits/stdc++.h>
using namespace std;

struct node{
    node* links[2]= {NULL};
    bool containsNode(int bit){
        return links[bit]!=NULL;
    }
    void putNode(int bit,node* tp){
        links[bit]=tp;
    }
    node* getNode(int bit){
        return links[bit];
    }
};


class Trie{
private: node* root;
public:
    Trie(){
        root=new node();
    }
    void constructTrie(vector<int>& arr1){
        for(int y: arr1){
            node* temp=root;
            int x=y;
            for(int i=31;i>=0;i--){
                int bt= (x>>i) & 1;
                if( !temp->containsNode(bt) ){
                    temp->putNode(bt,new node());
                }
                temp=temp->getNode(bt);
            }
        }
    }

    int maxEleXor(int x){
        node* temp=root;
        int res=0;
        for(int i=31;i>=0;i--){
            int f= (x>>i)&1;
            if( temp->containsNode(1-f) ){
                res= res | (1<<i);
                temp=temp->getNode(1-f);
            }
            else {

                temp=temp->getNode(f);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=-2147483648;
        Trie tr;
        tr.constructTrie(nums);
         for(int a:nums){
            res=max(res,tr.maxEleXor(a));
        }
        return res;
    }
};