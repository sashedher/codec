// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dis(V,INT_MAX);

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0,S});
        dis[S]=0;
        while(!q.empty()){
            auto t=q.top();
            q.pop();
            int n=t.second;
            int d=t.first;
            for(auto x:adj[n]){
                if(dis[n]+x[1] < dis[x[0]]){
                    dis[x[0]] = dis[n]+x[1];
                    q.push({dis[x[0]], x[0]});
                }
            }
        }
        return dis;
    }
};