#include<iostream>
using namespace std;
long long  int weirdalgo( long long int n){
    if(n==1)
        return 1;    
    if(n%2==0){
        cout<<n<<" ";
        return weirdalgo(n/2);
    } 
    else{
        cout<<n<<" ";
        return weirdalgo(3*n+1);
    }
}

int main(){
  long  long int x;
    cin>>x;
    x=weirdalgo(x);
    cout<<x;
    return 0;
}