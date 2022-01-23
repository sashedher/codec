#include<iostream>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int *A=new int[n]{7};
    for(i=0;i<n;i++)
        cout<<A[i]<<" ";
    return 0;
}