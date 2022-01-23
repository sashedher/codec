
#include<iostream>
using namespace std;
int main(){
    int p,t;
    cin>>t;
    while(t--){
        cin>>p;
        if(p%2) cout<<"2 "<<p-1<<endl;
        else cout<<"2 "<<p<<endl;
    }
    return 0;
}