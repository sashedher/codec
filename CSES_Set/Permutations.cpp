#include<iostream>
using namespace std;
int main(){
    long long int n,i=2;
    cin>>n;
    if(n==3 || n==2){
        cout<<" NO SOLUTION";
        return 0;
    }
    while(i<n+1){
        cout<<i<<" ";
        i+=2;
    }
    i=1;
    while(i<=n){
        cout<<i<<" ";
        i+=2;
    }
    return 0;
}