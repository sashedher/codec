// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    Node* get(int bit)
    {
        return links[bit];
    }
    void put(int bit,Node *nn)
    {
        links[bit]=nn;
    }
};
class Trie{
private:
    Node *root;
public:
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *node=root;
        //insert numbers in terms of all 32 bits 
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                Node *nn=new Node();
                node->put(bit,nn);
            }
            node=node->get(bit);
        }
    }
    //this function will return the maximum xor of num from all the trie elements
    int getMax(int num)
    {
        int res=0;
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            int flipbit=(1-bit); //in order to getmaximum xor
            if(node->containsKey(flipbit))
            {
                res=res|(1<<i); //make the result's ith bit as 1
                node=node->get(flipbit); //move to its reference
            }
            else{
                //result's ith bit will remain zero
                //move to next bit
                node=node->get(bit);
            }
        }
        return res;
    }
    
};
class Solution {
public:
    static bool comp(vector<int> &a ,vector<int> &b)
    {
        return a[1]<b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie trie;
        int n=queries.size();
        vector<int> res(n,0);
        for(int i=0;i<n;i++)
        {
            queries[i].push_back(i);
        }
        sort(nums.begin(),nums.end());
        sort(queries.begin(),queries.end(),comp);
        int j=0;
        for(int i=0;i<n;i++)
        {
            int maxi=0;
            int x=queries[i][0];
            int a=queries[i][1];
            while(j<nums.size() and nums[j]<=a)
            {
                trie.insert(nums[j]);
                j+=1;
            }
            if(j==0)
                res[queries[i][2]]=-1;
            else{
            maxi=trie.getMax(x);
            res[queries[i][2]]=maxi;
            }
        }
        return res;
    }
};