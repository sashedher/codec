// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,h=arr.size()-1;
        while(l<h){
            int m=l+(h-l)/2;
            // cout<<arr[m]<<" "<<m<<endl;
            if(arr[m]<arr[m+1]) l=m+1;
            else h=m;
        }
        return l;
        
    }
};