// https://leetcode.com/problems/duplicate-zeros/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i,0);
                i++;
            } 
        }
        arr.erase(arr.begin()+n,arr.end());
    }
};