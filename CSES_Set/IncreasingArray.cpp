#include<iostream>
using namespace std;
int main(){
   long long int n,s=0,i,t=0;
   cin>>n;
   int *a=new int[n];
   for(i=0;i<n;i++){
       cin>>a[i];
   }
   for(i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
          s=a[i]-a[i+1];
          a[i+1]+=s;
          t=t+s;
      } 
     
   }
   cout<<t;
   return 0;
}   