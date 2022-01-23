#include<iostream>
#include"SortAlgo.h"
using namespace std;

int main(){
    int i,j,n=16,t,k;
    //cin>>n;
    //int * A=new int[n];
    int A[]={-12,3,-12,4,1,1,-12,1,-1,1,2,3,4,2,3,-12};
    //for(i=0;i<n;i++){
      //A[i]=rand()%100+1;
    //}
    for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    sortQuick(A,0,n-1);
    cout<<"\n\n";
     for(i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    //delete[] A;
    return 0;
}