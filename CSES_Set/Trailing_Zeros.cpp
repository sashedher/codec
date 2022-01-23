#include<iostream>
using namespace std;
int main(){
    long long int n,s=0;
    cin>>n;
    while(n>1){
        s=s+n/5;
        n/=5;
    }
    cout<<s;
    return 0;
}