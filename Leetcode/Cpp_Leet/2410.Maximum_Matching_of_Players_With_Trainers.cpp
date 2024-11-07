// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end(),greater<int>());
        sort(trainers.begin(),trainers.end(),greater<int>());
        int n=players.size() ,m=trainers.size() ;
        int i=0,j=0, count=0;
        
        while(i<n && j<m){
            if(players[i]<=trainers[j]){
                count++;
                i++;
                j++;
            }
            else if(players[i]> trainers[j]) i++;
        }
        
        return count;
    }
};