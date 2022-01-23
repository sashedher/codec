// https://codeforces.com/contest/1624/problem/A --    x solved
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,mn=0,temp;
        cin>>n;
        vector<long long int> a;
        for(int i=0;i<n;i++){
            cin>>temp;
            a.push_back(temp);
        }

        cout<<*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end())<<endl;
        
    }
    return 0;
}
