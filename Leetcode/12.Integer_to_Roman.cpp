// https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n=num;
        string res="";
        
        
       int d1,d2,d3,d4;
        d1=num/1000;
        d2=(num/100)%10;
        d3=(num/10)%10;
        d4=num%10;
        // cout<<d1<<" "<<d2<<" "<< d3<<" "<<d4<<endl;
        while(d1--)    res=res+'M';
        if(d2>=5){
            if(d2==9) res=res+"CM";
            else{
                d2=d2-5;
                res=res+'D';
                while(d2--)    res=res+'C';
            }
        }
        else{
            if(d2==4) res=res+"CD";
            else{
                while(d2--)    res=res+'C';
            }
        }
        
        if(d3>=5){
            if(d3==9) res=res+"XC";
            else{
                d3=d3-5;
                res=res+'L';
                while(d3--)    res=res+'X';
            }
        }
        else{
            if(d3==4) res=res+"XL";
            else{
                while(d3--)    res=res+'X';
            }
        }
        
        if(d4>=5){
            if(d4==9) res=res+"IX";
            else{
                d4=d4-5;
                res=res+'V';
                while(d4--)    res=res+'I';
            }
        }
        else{
            if(d4==4) res=res+"IV";
            else{
                while(d4--)    res=res+'I';
            }
        }
        
        return res;
    }
};