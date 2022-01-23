// https://codeforces.com/problemset/problem/1350/A

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isPrime(int p){
    for(int x=2;x<=sqrt(p);x++){
        if(p%x==0) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    vector<int> pr={2,3};
    for(int  i=5;i<1000000;i++){
        if(isPrime(i)) pr.push_back(i);
    }
    // for(auto f:pr){
    //     cout<<f<<" ";
    // }
    // cout<<endl;
    while (t--){
        int n,k;
        cin>>n>>k;
        for(auto fr:pr){
            if(n%fr==0){
                n+=fr;
                break;
            }
        }
        n=n+(k-1)*2;        
        cout<<n<<endl;
    }    
    return 0;
}