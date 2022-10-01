// https://leetcode.com/problems/longest-uploaded-prefix/

#include<bits/stdc++.h>
using namespace std;

class LUPrefix {
public:
    vector<int> vid;
    int sz,res=0;
    LUPrefix(int n) {
        vid.resize(n+1,0);
        sz=n;
    }
    
    void upload(int video) {
        vid[video]=video;
    }
    
    int longest() {
        for(int i=res;i<=sz;i++){
            if(vid[i]==i) res=i;
            else break;
        }
        return res;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */