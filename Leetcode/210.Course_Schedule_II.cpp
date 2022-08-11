// https://leetcode.com/problems/course-schedule-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> vis(numCourses,false),dfsvis(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[ prerequisites[i][1] ].push_back(prerequisites[i][0]);
        }
        
        
       //cycle check-dependency check
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
                        // res.push_back(t);
                        
                    }
                    
                    for(int j=0;j<adj[t].size();j++){
                        if( vis[ adj[t][j] ]==false ){
                            st.push( adj[t][j] );

                        }
                        else if(dfsvis[ adj[t][j] ] ) return {};
                    }

                    
                }

            }
        }
        //topological sort
        vector<int> deg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                deg[ adj[i][j] ]++;
            }
        }

        vector<int> res;
        queue<int> tp;
        for(int i=0;i<numCourses;i++) if(deg[i]==0) tp.push(i);
        while(!tp.empty()){
            int t=tp.front();
            tp.pop();
            res.push_back(t);
            for(int j=0;j<adj[t].size();j++){
                       deg[ adj[t][j] ]--;
                if(deg[ adj[t][j] ]==0) tp.push(adj[t][j]);
           }


        }

       return res;
       
    }
};