// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        multiset<int> tr(target.begin(),target.end());
        for(int x:arr){                                     //map every element in arr to target vector using multiset if mapped return true else return false
            multiset<int> :: iterator it=tr.find(x);
            if(it==tr.end()) return false;
            else tr.erase(it);
        }
        return true;
    }
};
