// https://leetcode.com/problems/course-schedule/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> vis(numCourses,false),dfsvis(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[ prerequisites[i][1] ].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
                
                stack<int> st;
                st.push(i);
                
                
                while(!st.empty()){
                    int t=st.top();
                    
                    if(!vis[t]){
                        vis[t]=true;
                        dfsvis[t]=true;
                    }
                    else{
                        dfsvis[t]=false;
                        st.pop();
                    }
                    
                    for(int j=0;j<adj[t].size();j++){
                        if( vis[ adj[t][j] ]==false ){
                            st.push( adj[t][j] );

                        }
                        else if(dfsvis[ adj[t][j] ] ) return false;
                    }

                    
                }
                        
            }
        }
        
        return true;       
    }
};