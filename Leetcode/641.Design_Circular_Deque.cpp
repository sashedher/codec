// https://leetcode.com/problems/design-circular-deque/

#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> cq;
    int s;
    MyCircularDeque(int k) {
        s=k;
    }
    
    bool insertFront(int value) {                 // insert at front
        if(isFull()) return false;
        cq.insert(cq.begin(),value);
        return true;
    }
    
    bool insertLast(int value) {                 // insert at rear
        if(isFull()) return false;
        cq.push_back(value);
        return true;
    }
    
    bool deleteFront() {                        // remove at front
        if(isEmpty()) return false;
        cq.erase(cq.begin());
        return true;
    }
    
    bool deleteLast() {                          // remove at rear
        if(isEmpty()) return false; 
        cq.pop_back();
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1; 
        return cq[0];
    }
    
    int getRear() {
        if(isEmpty()) return -1; 
        return cq[cq.size()-1];
    }
    
    bool isEmpty() {
        return cq.size()==0;
    }
    
    bool isFull() {
        return cq.size()==s;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */