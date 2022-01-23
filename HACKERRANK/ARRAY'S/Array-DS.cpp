#include<iostream>
using namespace std;
void RevArray(int* b,int n){
    if(n<1)
        return;
    else {
        RevArray(b+1,n-1);
        cout<<*b<<" ";
    }
}
int main(){
    int n,i=0;
    cin>>n;
    int *a=new int[n];
    for ( i = 0; i < n; i++){
        cin>>a[i];  
    }
    cout<<"using simple for loop : ";
    for ( i =n-1; i >= 0; i--){
        cout<<a[i]<<" ";  
    }
    cout<<"\nusing Recurssion : ";
    RevArray(a,n);
    
    return 0;
}