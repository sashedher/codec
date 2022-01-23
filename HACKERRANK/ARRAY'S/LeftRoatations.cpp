#include<iostream>
//if no.of (d)left rotation are more then use (n-d) right rotations  to avoid time out error
using namespace std;
int main()
{
     long long int n,d,i,j,t,s;
    cin>>n>>d;
    long long int *a=new long long int[n];
    if(d<=n){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        s=n-d;
        if(s>=d){                                               // d Left Rotations 
            for(j=0;j<d;j++){
                t=a[0];
                for(i=0;i<n-1;i++){
                    a[i]=a[i+1];
                }   
                a[n-1]=t;
            }
        }
        else{                                                  // n-d Right Rotations
            for(j=0;j<s;j++){
                t=a[n-1];
                for(i=n-1;i>0;i--){
                    a[i]=a[i-1];
                }
                a[0]=t;
            }
        }
        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
