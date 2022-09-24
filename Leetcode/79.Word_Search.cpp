// https://leetcode.com/problems/word-search/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool wordsearch(vector<vector<char>>& board,int i,int j,int ind,string &word,int nr,int nc){
        if(ind==word.length()) return true;
       
        if(i<0 || j<0 || i==nr || j==nc || board[i][j]=='.' || board[i][j]!= word[ind] ) return false;  
            
        char c= board[i][j];
        board[i][j]='.';
        
        bool t= wordsearch(board,i-1,j,ind+1,word,nr,nc);
        bool b= wordsearch(board,i+1,j,ind+1,word,nr,nc);
        bool l= wordsearch(board,i,j-1,ind+1,word,nr,nc);
        bool r= wordsearch(board,i,j+1,ind+1,word,nr,nc);
        
        board[i][j]=c;
            
                   
        return t || b || l || r ;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size() ,n=board[0].size() ;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(wordsearch(board,i,j,0,word,m,n))
                      return true;
                }       
            }
        }
        return false;
    }
};