// https://leetcode.com/problems/lemonade-change/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5=0,c10=0,n=bills.size();
        for(int i=0;i<n;i++){
            
            if(bills[i]==5){
                c5++;
            }
            else if(bills[i]==10){
                if(c5<=0) return false;
                c5--;
                c10++;
            }
            else{
               
                if(c5<=0) return false;
                else{
                    if(c10>0) {c5--;c10--;}
                    else if(c5>2) c5=c5-3;
                    else return false;
                }       
                
            }
            
            // cout<<c5<<" "<<c10<<" "<<bills[i]<<endl;
        
        }
        return true;
    }
};