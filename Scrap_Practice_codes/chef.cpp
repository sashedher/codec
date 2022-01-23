#include <iostream>
using namespace std;
int main() {
    int t,n,k,i,s=0,y=0,temp=0;
    bool x=true;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int* w=new int[n];
        for(i=0;i<n;i++){
            cin>>w[i];
        }
        s=0;
        l:s=s+w[i];
        if(s<=k){
            i++;
            goto l;
        }
        else
        {
            s=0;
            y++;
            goto l;
        }
        cout<<y<<"\n";
    }
    return 0;
}