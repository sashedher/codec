// https://leetcode.com/problems/sudoku-solver/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checknum(vector<vector<char>>& board,int row, int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
            if(board[row/3*3+i/3][col/3*3+i%3]==c) return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board ){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        
                        if(checknum(board,i,j,c)){
                            board[i][j]=c;
                            
                            if(backtrack(board)) return true;               // return true to know to continue with next number
                            else    board[i][j]='.';
                            
                        }
                    }
                    return false;                                           // else return false to continue with next number
                }
                
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};