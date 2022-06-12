// https://practice.geeksforgeeks.org/problems/find-distinct-elements2054/1#

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        unordered_map<int,int> mp;                                  //by using map results in TLE,change to Unordered_map to accept
        int count=0;
        for(int i=0;i<N;i++){
            set<int> s(M[i].begin(),M[i].end());                    //to count unique elements in each row
            
            for(int x: s){
                if(mp.find(x)==mp.end()) mp[x]=1;
                else mp[x]++;
            }
            
        }
        for(unordered_map<int,int> ::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second==N) count++;                                              //count #of elements  equal to #of rows so that  element is common in every row
        }
     return count;   
    }
};