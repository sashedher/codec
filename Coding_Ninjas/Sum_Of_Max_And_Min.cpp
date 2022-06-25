// https://www.codingninjas.com/codestudio/problems/sum-of-max-and-min_1081476?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

// using Divide and conquer approach

pair<int,int> DCMinMax(vector<int> ar){
    int n=ar.size();
    if(n==1) return {ar[0],ar[0]};
    if(n==2){
        int mn,mx;
        mn=min(ar[0],ar[1]);
        mx=max(ar[0],ar[1]);
        return {mn,mx};
    }
    else{
        pair<int,int> f1,f2;
        int mn,mx;
        f1=DCMinMax({ar.begin(),ar.begin()+n/2});
        f2=DCMinMax({ar.begin()+n/2,ar.end()});
        mn=min(f1.first,f2.first);
        mx=max(f1.second,f2.second);
        return {mn,mx};
    }
}

int sumOfMaxMin(int arr[], int n){
	// Write your code here.
    vector<int> ar(arr,arr+n);
    pair<int,int> x=DCMinMax(ar);
    return x.first+x.second;
}