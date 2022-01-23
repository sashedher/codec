#include<iostream>
using namespace std;
int main(){
     long int t;
    cin>>t;
    while(t--){
       long long int n,k,a,b;
        cin>>n>>k;
        if(k==1) cout<<"1\n";
        else{
            a=n;b=1;
            if(k>n)  
           
            while(k--){
                a=a-1;
                b+=1;
                if(a==0) a=n;
                if(b==n+1) b=1;
                if(a==b){
                    b+=1;
                    if(b==n+1) b=1;
                }
               
                
            }
            cout<<b<<"\n";
        }
    }
    return 0;
}