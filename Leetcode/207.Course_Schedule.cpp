// https://leetcode.com/problems/course-schedule/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> deg(numCourses,0),res;
        
        for(int i=0;i<prerequisites.size();i++){
            adj[ prerequisites[i][1] ].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++){
	        for(int j=0;j<adj[i].size();j++){
	            deg[ adj[i][j] ]++;
	        }
	    }
        
        queue<int> q;
	    for(int i=0;i<numCourses;i++){
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
	    return res.size()==numCourses;
    }
};