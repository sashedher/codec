// https://www.interviewbit.com/problems/add-binary-strings/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 

    string addBinary(string A, string B) {
        int n1=A.length(),n2=B.length();
        string res;

        int i=n1-1,j=n2-1,a=0,b=0,c=0,s=0;
        while((i>=0 || j>=0) || c!=0){
            a = (i>=0) ? A[i]-'0' : 0;
            b = j>=0 ? B[j] -'0': 0;
            s = a+b+c;
            c=s/2;
            s=s%2;
            // cout<<s <<" "<<c;
            // char t=s+'0';
            res=to_string(s)+res;
            i--;
            j--;
        }
        return res;
    }


};


