// https://codeforces.com/contest/1629/problem/A  Inprocess
#include<bits/stdc++.h>
using namespace std;
 void solve(){

    
    int n,k;
    cin>>n>>k;
    vector<pair<int, int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }     
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }    
    sort(a.begin(),a.end());
    
    for(int i=0;i<n;i++){
        if(a[i].first<=k){
            k=k+a[i].second;
        }
    } 
    cout<<k<<"\n";
 }


int main(){
    int t;
    cin>>t;
    while(t--){
       solve();
    }
    
    return 0;
}
