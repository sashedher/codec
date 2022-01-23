#include<bits/stdc++.h>
using namespace std;
#define  floop(i,n) for(int i=0;i<n;i++) 
int main(){
    int n,t,s=0,sum,i,j,flag=0;
    cin>>t;
    while(t--){
        cin>>n>>sum;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            s=0;
            flag=0;
            for(int j=i;j<n;j++){
                s=s+A[j];
                if(s==sum){
                    flag=1;
                    cout<<i+1<<" "<<j+1<<endl;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==0) cout<<"-1"<<endl;
    }
    
    
    
    return 0;

}