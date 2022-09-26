// https://leetcode.com/problems/design-circular-queue/

#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> q;
    int f,r,sz;
    MyCircularQueue(int k) {
        q.resize(k,-1);
        f=-1,r=-1;
        sz=k;
    }
    
    bool enQueue(int value) {
        if( (r+1)%sz ==f) return false;
        else{
            if(r==-1 && f==-1 ) f=r=0;
            else r=(r+1)%sz;
            q[r]=value;
            return true;
        }
    }
    
    bool deQueue() {
        if( f==-1 && r==-1) return false;
        
        else{
            q[f]=-1;
            if(f==r)    f=r=-1;
            else    f=(f+1)%sz;
            return true;
        }
    }
    
    int Front() {
        
        if(f==-1) return -1;
        else return q[f];
    }
    
    int Rear() {
        if(r==-1) return -1;
        else return q[r];
    }
    
    bool isEmpty() {
        return f==-1;
    }
    
    bool isFull() {
        return (r+1)%sz==f;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */