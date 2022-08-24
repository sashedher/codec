// https://leetcode.com/problems/available-captures-for-rook/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rr=0,rc=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    rr=i,rc=j;
                    break;
                }
            }
            
        }
        int res=0;
        
        int j=rc+1;
        while(j<8){
            if(board[rr][j]=='.') j++;
                
            else if(board[rr][j]=='B') break;
            else{
                res++;
                break;
            }
        }
        
        j=rc-1;
        while(j>=0){
            if(board[rr][j]=='.') j--;
            else if(board[rr][j]=='B') break;
            else{
                res++;
                break;
            }
        }
        
        
        int i=rr-1;
        while(i>=0){
            if(board[i][rc]=='.') i--;
            else if(board[i][rc]=='B') break;
            else{
                res++;
                break;
            }
        }
        
        i=rr+1;
        while(i<8){
            if(board[i][rc]=='.') i++;
            else if(board[i][rc]=='B') break;
            else{
                res++;
                break;
            }
        }
        
        return res;
    }
};