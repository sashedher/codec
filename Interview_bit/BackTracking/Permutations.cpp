// https://www.interviewbit.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> res;
int n=0;

void BackTrack(vector<int> &A,int index){
    if(index>n) return ;
    if(index==A.size()){
        res.push_back(A);
        return;
    }

    for(int i=index;i<n;i++){
        swap(A[i],A[index]);
        BackTrack(A,index+1);
        swap(A[i],A[index]);
    }
    
}





class Solution{
public: 

    vector<vector<int> > permute(vector<int> &A) {
        n=A.size();
        res.clear();
        BackTrack(A,0);
        return res;
    }

};