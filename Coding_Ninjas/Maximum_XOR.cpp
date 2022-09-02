// https://www.codingninjas.com/codestudio/problems/maximum-xor_973113?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// insert one array into trie and find maximum using another array 

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
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    int res=-2147483648;
    Trie tr;
    tr.constructTrie(arr1);
    for(int a:arr2){
        res=max(res,tr.maxEleXor(a));
    }
//     free(root);
    return res;
}