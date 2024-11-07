// https://leetcode.com/problems/design-front-middle-back-queue/

#include<bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    vector<int> q;
    FrontMiddleBackQueue() {
        q.clear();
    }
    
    void pushFront(int val) {
        q.insert(q.begin(),val);
    }
    
    void pushMiddle(int val) {
        int x=q.size();
        x=x/2;
        q.insert(q.begin()+x,val);
        
    }
    
    void pushBack(int val) {
        q.push_back(val);
    }
    
    int popFront() {
        if(q.size()==0) return -1;
        int ele=q[0];
        q.erase(q.begin());
        return ele;
    }
    
    int popMiddle() {
        if(q.size()==0) return -1;
        int x=q.size(),ele=0;
        x=x%2?x/2:x/2-1;
        ele=q[x];
        q.erase(q.begin()+x);
        
        return ele;
    }
    
    int popBack() {
        int x=q.size(),ele;
        if(x==0) return -1;
        ele=q[x-1];
        q.pop_back();
        return ele;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */