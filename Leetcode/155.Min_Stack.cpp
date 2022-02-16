// https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    long m;
    stack<long> s;
    MinStack() {
    }
    
    void push(int val) {
        if(s.size()==0){   
            m=val;
            s.push(val);
        }
        else if(val<m){
            s.push((long)2*val-m);
            m=val;
        }
        else s.push(val);
    }
    
    void pop() {
        if(s.top()<m){
            m=(long)(2*m-s.top());
            s.pop();
        }
        else s.pop();   
    }
    
    int top() {
        if(s.top()<m){
            return m;
        }
        else return s.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */