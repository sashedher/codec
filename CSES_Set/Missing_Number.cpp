#include<iostream>
using namespace std;
int main(){
   long long int n,s=0,i;
   cin>>n;
   int *a=new int[n-1];
   for(i=0;i<n-1;i++){
       cin>>a[i];
       s+=a[i];
   }
   n=(n*(n+1))/2;
   s=n-s;
   cout<<s;
delete[] a;
return 0;
}