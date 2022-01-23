#include<iostream>
using namespace std;
int main(){
    int n,m,i,q,li=0,x,y,t;
    cin>>n;
    int **a=new int*[n];
     for(i=0;i<n;i++){
         int *b=new int[n];
         a[i]=b;
     }
    cin>>q;
    for(i=0;i<q;i++){
        cin>>m>>x>>y;
        if(m==1){
            t=(x^li)%n;
            //a[t][]=y;
        }
    }

    return 0;
}