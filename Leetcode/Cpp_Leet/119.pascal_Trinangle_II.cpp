// https://leetcode.com/problems/pascals-triangle-ii/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int fact(int x){
        if(x==0 || x==1 ) return 1;
        long long int r=1;
        for(int i=2;i<=x;i++){
            r*=i;
        }
        return r;
    }
    
    vector<int> getRow(int n) {
        vector<int> pt(n+1,0);
        int nf=fact(n);
        for(int i=0;i<=n/2;i++){
            int nm=1,dm=1;
            for(int j=n;j>i;j--){
                nm=nm *(nm+1);
                dm*=j;
            }
            
            
            pt[i]= nm/dm;
            pt[n-i]=nm/dm;
                
        }
        return pt;
        
        
        
        
        
        
        
        
//         pt.push_back({1});
//         if(n==0) return pt[0];

//         for(int i=1;i<=n;i++){
//             pt.push_back({});
//             for(int j=0;j<=pt[i-1].size();j++){
//                 if(j==0 || j==pt[i-1].size()){
//                     pt[i].push_back(1);
//                 }
//                 else pt[i].push_back(pt[i-1][j-1]+pt[i-1][j]);
//             }
//         }
//         return pt[n];
    }
};