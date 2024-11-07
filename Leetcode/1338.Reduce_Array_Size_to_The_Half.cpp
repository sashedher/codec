

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> nf;
        vector<int> t;
        int n1=arr.size(),res=0,c=0;
        
        for(int x:arr){
            nf[x]++;
        }
        
        for(map<int,int> :: iterator it=nf.begin();it!=nf.end();it++){
            t.push_back(it->second);    
        }

        sort(t.begin(),t.end(),greater<int>());

        int n2=t.size();
        for(int i=0;i<n2;i++){
            
            if(c>=n1/2) break;
            else{
                c+=t[i];
                res++;
            }
        }
        
        return res;
    }
};