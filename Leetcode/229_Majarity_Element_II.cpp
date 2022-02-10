// https://leetcode.com/problems/majority-element-ii/ -Accepted TC : O(n), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

// TC : O(n), SC : O(1) using Boyer-Moore  voting Algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0,e1=0,e2=0;
        vector<int> res;
        for(int a:nums){
            if(e1==a) c1++;
            else if(e2==a) c2++;
            else if(c1==0){e1=a;c1=1;}
            else if(c2==0){e2=a;c2=1;}
            else{c1--;c2--;}
        }
        int c11=0,c22=0;
        for(int a:nums){
            if(a==e1) c11++;
            else if(a==e2) c22++;
        }
        if(c11>nums.size()/3) res.push_back(e1);
        if(c22>nums.size()/3) res.push_back(e2);
        
        return res;
    }
    
};




int main(){
    Solution ob;
    vector<int> nums={3};
    vector<int> it=ob.majorityElement(nums);
    cout<<"res vector size "<<it.size()<<endl;
    for (auto i = it.begin(); i !=it.end(); i++)    {
        /* code */
        cout<<*i<<" ";
    }
    cout<<endl;
    
    return 0;
}
