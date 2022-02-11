// https://www.interviewbit.com/problems/max-min/ -tried Divide and conquer but results in TLE

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) { 
    int x=*max_element(A.begin(),A.end()) ;
    int y=*min_element(A.begin(),A.end());
    return x+y;    
}

/*
pair<int,int> MinMax(vector<int> A,int l,int h){
    int m=(l+h)/2;
    pair<int,int> lf,rg,res;
    if(l==h){
        res.first=A[l];
        res.second=A[l];
        return res;
    }
    else if(l!=h){
        lf=MinMax(A,l,m);
        rg=MinMax(A,m+1,h);
    }
    
    if(lf.first<=rg.first)  res.first=lf.first;
    else    res.first=rg.first;

    if(lf.second>=rg.second)  res.second=lf.second;
    else    res.second=rg.second;

    return res;

}
*/