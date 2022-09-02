// https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;
  
//sort both queries and arr and maintain trie accourding to query integer

bool compare(vector<int> a, vector<int> b){
    return a[1]< b[1];
}
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
    void insert(int x){
        
            node* temp=root;
           
            for(int i=31;i>=0;i--){
                int bt= (x>>i) & 1;
                if( !temp->containsNode(bt) ){
                    temp->putNode(bt,new node());
                }
                temp=temp->getNode(bt);
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
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    Trie tr;
    int n=queries.size(),n1=arr.size();
    vector<int> res(n,0);
    vector<vector<int>> qrs(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
        qrs[i][0]=queries[i][0];
        qrs[i][1]=queries[i][1];
        qrs[i][2]=i;
    }
    sort(qrs.begin(),qrs.end(),compare);
    sort(arr.begin(),arr.end());
    int i=0, j=0;
    while(i<n){
        
        while(j<n1 && arr[j]<=qrs[i][1]) {
            tr.insert(arr[j]);
            j++;
        }
        if(j==0) res[qrs[i][2]]=-1;
        else res[qrs[i][2]]=tr.maxEleXor(qrs[i][0]);
        i++;
    }
    
    return res;
}