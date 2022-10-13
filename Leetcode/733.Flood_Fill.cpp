// https://leetcode.com/problems/flood-fill/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int m=image.size(),n= image[0].size();
        queue<pair<int,int>> q;
        vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        q.push({sr,sc});
        int pc=image[sr][sc];
        image[sr][sc]=color;
      
        while(!q.empty()){
            pair<int,int> t=q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x= t.first+v[i].first;
                int y= t.second+v[i].second;
                if(x>=0 && x<m && y>=0 && y<n &&  image[x][y]==pc){
                    q.push({x,y});
                    image[x][y]=color;
                    
                }
            }
        }
        
        return image;
    }
};