// https://leetcode.com/problems/count-days-spent-together/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dm={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
   int days(int x,int y){
            int d=0;
            for(int i=0;i<x-1;i++){
                d+=dm[i];
            }
            return d+y;
        
    }
    
   
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        int aam= ( arriveAlice[0]-'0') *10 + arriveAlice[1]-'0';
        int aad= ( arriveAlice[3]-'0') *10 + arriveAlice[4]-'0';
        int abm= ( arriveBob[0]-'0') *10 + arriveBob[1]-'0';
        int abd= ( arriveBob[3]-'0') *10 + arriveBob[4]-'0';
        
        int lam= ( leaveAlice[0]-'0') *10 + leaveAlice[1]-'0';
        int lad= ( leaveAlice[3]-'0') *10 + leaveAlice[4]-'0';
        int lbm= ( leaveBob[0]-'0') *10 + leaveBob[1]-'0';
        int lbd= ( leaveBob[3]-'0') *10 + leaveBob[4]-'0';
        
        pair<int,int> alice,bob;
        alice.first=days(aam,aad);
        alice.second=days(lam,lad);
        bob.first=days(abm,abd);
        bob.second=days(lbm,lbd);
        
        int x = max( alice.first , bob.first );
        int y = min( alice.second , bob.second );
            
        if(x<=y) return y-x+1;
        else return 0;
    }
};