// https://www.interviewbit.com/problems/repeat-and-missing-number-array/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution{
public: 

    vector<int> repeatedNumber(const vector<int> &A) {
    vector<int> res;
    int s=0;  
    int c=accumulate(A.begin(),A.end(),0);      
    for(int i=0;i<A.size();i++){
        s=s^A[i];
    }
    for(int i=1;i<=A.size();i++){
        s=s^i;
    }
    // s=s^15; 
    cout<<s<<endl;

    return res;
    }


};
int main(){
    Solution o;
    vector<int> a={3,1,2,5,3};
    o.repeatedNumber(a);

    return 0;
}