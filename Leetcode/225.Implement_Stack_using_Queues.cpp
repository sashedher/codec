// https://leetcode.com/problems/implement-stack-using-queues/

#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q1,q2,temp;
    MyStack() {
        
    } 
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int x;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        x=q1.front();
        q1.pop();
        temp=q1;
        q1=q2;
        q2=temp;
        return x;
    }
    
    int top() {
        int x;
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        x=q1.front();
        q1.pop();
        q2.push(x);
        temp=q1;
        q1=q2;
        q2=temp;
        return x;
        
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */