// https://practice.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void insertBottom(stack<int> &res, int x){     // 2nd recurssion call to insert every new element in the bottom of stack
        if(res.empty()){
            res.push(x);
            return;
        }
        int t=res.top();
        res.pop();
        insertBottom(res,x);
        res.push(t);
    }
    void ReverseStack(stack<int> &st){             // from reverse send every new element to InsertBottom function  to insert at bottom of stack
        if(st.empty()) return;
        else{
            int t=st.top();
            st.pop();
            ReverseStack(st);
            insertBottom(st,t);
        }
    }
    stack<int> Reverse(stack<int> St){              //main-solution function
       
        ReverseStack(St);
        return St;
    }
};