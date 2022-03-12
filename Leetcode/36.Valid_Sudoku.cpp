// https://leetcode.com/problems/valid-sudoku/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        
        for(int i=0;i<n;i++){
            set<char> r,c;
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    if(r.find(board[i][j])!=r.end()) return false;
                    else      r.insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    if(c.find(board[j][i])!=c.end()) return false;
                    else      c.insert(board[j][i]);
                    
                }
            }
            
        }
        for(int p=0;p<3;p++){
            for(int k=0;k<3;k++){
                    set<char> bx1;
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                           if(board[k*3+i][p*3+j]!='.'){
                                if(bx1.find(board[k*3+i][p*3+j])!=bx1.end()) return false;
                                else      bx1.insert(board[k*3+i][p*3+j]);
                            }

                        }
                    }
                
            }
            
        }
            
        return true;
        
    }
};