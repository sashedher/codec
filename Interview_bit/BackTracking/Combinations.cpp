// https://www.interviewbit.com/problems/combinations/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> res;

void BackTrack(vector<int> ar,vector<int> ans,int B,int index){
    if(ans.size()==B){
        res.push_back(ans);
    }
    else{

        for(int i=index;i<ar.size();i++){
            ans.push_back(ar[i]);
            BackTrack(ar,ans,B,i+1);
            ans.pop_back();
        }

    }


}
class Solution{
public: 

    vector<vector<int> > combine(int A, int B) {
        vector<int> ar(A);
        
        for(int i=1;i<=A;i++){
            ar[i-1]=i;
        }
        
        res.clear();
        BackTrack(ar,{},B,0);

        return res;

    }

};