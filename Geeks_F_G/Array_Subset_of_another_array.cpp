// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1

#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {
    
    set<int> s2(a1,a1+n);
    for(int i=0;i<m;i++){
        if(s2.find(a2[i])==s2.end()) return "No";
    }
    return  "Yes";
}