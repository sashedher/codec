// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i = 1;i < N; i++){
            string s1,s2;
            s1=dict[i-1];
            s2=dict[i];
            int m=s1.length(), n= s2.length();
            
            for(int j=0; j<min(m,n); j++){
                if(s1[j]!= s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        vector<int> deg(K,0);
        for(auto x:adj){
            for(int y:x){
                deg[y]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++){
            if(deg[i]==0) q.push(i);
        }
        string res="";
        while(!q.empty()){
            int t=q.front();
            q.pop();
            res=res+(char)(t+'a');
            for(auto x:adj[t]){
                deg[x]--;
                if(deg[x]==0) q.push(x);
            }
        }
        // cout<<res<<endl;
        return res;
    }
};