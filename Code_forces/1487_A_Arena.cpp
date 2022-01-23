#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s=200,r=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=s){
                s=a[i];
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==s) r++;
        }
        cout<<n-r<<"\n";
    }

    return 0;
}