// https://leetcode.com/problems/determine-if-two-events-have-conflict/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int e1h1,e1h2,e2h1,e2h2;
        e1h1= (event1[0][0]-'0')*10+event1[0][1]-'0';
        e1h2= (event1[1][0]-'0')*10+event1[1][1]-'0';
        e2h1= (event2[0][0]-'0')*10+event2[0][1]-'0';
        e2h2= (event2[1][0]-'0')*10+event2[1][1]-'0';
        
        // cout<<e1h1<<" "<<e1h2<<" "<<e2h1<<" "<<e2h2<<endl;
        
        int e1m1,e1m2,e2m1,e2m2;
        e1m1= (event1[0][3]-'0')*10+event1[0][4]-'0';
        e1m2= (event1[1][3]-'0')*10+event1[1][4]-'0';
        e2m1= (event2[0][3]-'0')*10+event2[0][4]-'0';
        e2m2= (event2[1][4]-'0')*10+event2[1][4]-'0';
        
        // cout<<e1m1<<" "<<e1m2<<" "<<e2m1<<" "<<e2m2<<endl;
        pair<int,int> e1,e2;
        e1.first=e1h1*60+e1m1;
        e1.second= e1h2*60+ e1m2;
        e2.first=e2h1*60+e2m1;
        e2.second= e2h2*60+ e2m2;
        
        return max(e1.first,e2.first) <= min(e1.second,e2.second);
    }
};