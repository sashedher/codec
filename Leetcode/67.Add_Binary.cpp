 
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    
        string st;
        int l1=a.length(),l2=b.length(),c=0,s=0,x=0,y=0;
        for(int i=l1-1,j=l2-1;(i>=0 || j>=0) || c!=0 ; i--,j--){
            x= (i>=0) ? 48-a[i] : 0;
            y= (j>=0) ? 48-b[j]  : 0;
            
            s=x+y+c;
            c=s/2;
            s=s%2;
            st.insert(st.begin(),48-s);
        }
        
        return st;
        
    }
};