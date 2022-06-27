// https://www.codingninjas.com/codestudio/problems/rotate-array_1230543?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& ar,int l,int h){
    for(int i=l,j=h-1;i<j;i++,j--){
        swap(ar[i],ar[j]);
    }
}



void rotate(vector<int> &ar,int k,int n){
    reverse(ar,0,k);
    reverse(ar,k,n);
    reverse(ar,0,n);
}

int main() {
    //Write your code here
    int N;
    cin>>N;
    vector<int> ar(N,0);
    for(int i=0;i<N;i++)    cin>>ar[i];
    int k;
    cin>>k;
    rotate(ar,k,N);
    for(int x:ar) cout<< x<<" ";
    cout<<endl;
    return 0;
}