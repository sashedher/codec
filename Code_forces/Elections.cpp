// https://codeforces.com/contest/1593/problem/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    long int a,b,c,x,p,q,r;
    cin>>x;
    while(x--){
        long int t1,t2,t3,zero=0;
        cin>>a>>b>>c;
        max(a,b);
        cout<<max(zero,max(b,c)-a+1)<<" "<<max(zero,max(a,c)-b+1)<<" "<<max(zero,max(b,a)-c+1)<<endl;        
    }
    return 0;
}










