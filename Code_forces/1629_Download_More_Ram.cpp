// https://codeforces.com/contest/1629/problem/A  solved

#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> x,pair<int,int> y){
    return x.first<y.first;
}

int main(){
    int t;
    cin>>t;
    while(t--){  
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
        }     
        for(int i=0;i<n;i++){
            cin>>a[i].second;
        }    
        sort(a.begin(),a.end(),comp);
        
        for(int i=0;i<n;i++){
          if(a[i].first<=k){
              k+=a[i].second;
            }
          else break;
        } 
        cout<<k<<"\n";
    }
    
    return 0;
}
