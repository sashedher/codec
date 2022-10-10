// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int BinSearch(vector<int>& nums,int tar){
        int l=0,h=nums.size()-1,m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]==tar) return m;
            else if(nums[m]>tar) h=m-1;
            else l=m+1;
        }
        return -1;
        
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(root){
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        int l,h,n=arr.size();
        for(int i=0;i<n;i++){
            l=i;
            h=BinSearch(arr,k-arr[i]);
            if((h!=-1 && arr[i]+arr[h]==k)&& i!=h) return true;
        }
        return false;
        
    }
};