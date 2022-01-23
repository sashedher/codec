// https://codeforces.com/contest/1629/problem/A  Inprocess
#include<bits/stdc++.h>
using namespace std;

bool comp(pair<long long int,long long int> x,pair<long long int,long long int> y){
    return x.first<y.first;
}

int main(){
    long long int t;
    cin>>t;
    while(t--){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        
        long long int n,k=0;
        cin>>n>>k;
        vector<pair<long long int,long long int>> a(n);
        for(long long int i=0;i<n;i++){
            cin>>a[i].first;
        }     
        for(long long int i=0;i<n;i++){
            cin>>a[i].second;
        }    
        sort(a.begin(),a.end(),comp);
        
        for(long long int i=0;i<n;i++){
          if(a[i].first<=k){
              k=k+a[i].second;
            }
          else break;
        } 
        cout<<k<<" "<<t+1<<"\n";
    }
    
    return 0;
}
