// https://practice.geeksforgeeks.org/problems/40c021237f84e4abd74e2025f06221fb4cf4cd85/1?page=2&category[]=BFS&sortBy=submissions

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    
    
    
    bool isprime(int x){
        int n=sqrt(x);
        for(int i=2;i<=n;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    bool check(int x,int y){
        int c=0;
        while(x>0 && y>0){
            if(x%10!=y%10) c++;
            x/=10;
            y/=10;
        }
        return c==1;
    }
    
    int solve(int Num1,int Num2)
    {   
        vector<int> primes;
        vector<vector<int>> adj(10000);
        vector<int> vis(10000,0); 
        
        for(int i=1000;i<9999;i++){
            if(isprime(i)) primes.push_back(i);
        }
        
        int n=primes.size();
        

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                
                if( i<j && check( primes[i] , primes[j]) ){
                    adj[primes[i]].push_back(primes[j]);
                    adj[primes[j]].push_back(primes[i]);
                }
                
            }
        }
        
        int dis=-1;
        queue<pair<int,int>> q;
        q.push({Num1,0});
        vis[Num1]=1;
        while(!q.empty()){
            pair<int,int> t=q.front();
            
            if(t.first==Num2) return t.second;
            q.pop();
            for(int i=0;i<adj[t.first].size();i++){
                if(vis[adj[t.first][i]]==0){
                    vis[adj[t.first][i]]=1;
                    q.push({adj[t.first][i],t.second+1});
                }
            }
        }
        return -1;
    }
};