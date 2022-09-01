// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> deg(V,0);
	    vector<int> res;
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            deg[ adj[i][j] ]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(deg[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int t= q.front();
	        q.pop();
	        res.push_back(t);
	        for(int i=0;i<adj[t].size();i++){
	            deg[adj[t][i]]--;
	            if( deg[ adj[t][i] ] ==0 ) q.push(adj[t][i]);
	        }
	        
	    }
	    return res;
	}
};