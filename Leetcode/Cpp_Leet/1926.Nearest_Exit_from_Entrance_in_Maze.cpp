// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int x=entrance[0],y=entrance[1];
        int m=maze.size(),n=maze[0].size();
        q.push({x,y}), maze[x][y]='-';
        int c=-1;
        if(x==0 || y==0 || x==m-1 || y==n-1){
            c++;
            q.pop();
             cout<<"("<<x<<","<<y<<") ";
            if(x-1>=0 && maze[x-1][y]=='.') q.push({x-1,y}), maze[x-1][y]='-';
            if(x+1<m && maze[x+1][y]=='.') q.push({x+1,y}), maze[x+1][y]='-' ;
            if(y-1>=0 && maze[x][y-1]=='.') q.push({x,y-1}), maze[x][y-1]='-';
            if(y+1<n && maze[x][y+1]=='.') q.push({x,y+1}), maze[x][y+1]='-';
        }
        while(!q.empty()){
            int s=q.size();
            c++;
            while(s--){
                pair<int,int> t=q.front();
                x=t.first,y=t.second;
                q.pop();
                cout<<"("<<x<<","<<y<<") ";
                if(x==0 || y==0 || x==m-1 || y==n-1){
                 if(maze[x][y]!='+') return c;   
                }
                else{
                    
                        if(maze[x-1][y]=='.') q.push({x-1,y}), maze[x-1][y]='-';
                        if(maze[x][y-1]=='.') q.push({x,y-1}), maze[x][y-1]='-';   
                    
                    
                        if(maze[x+1][y]=='.') q.push({x+1,y}), maze[x+1][y]='-';
                        if(maze[x][y+1]=='.') q.push({x,y+1}), maze[x][y+1]='-';
                }
            }
            
        }
        return -1;
    }
};