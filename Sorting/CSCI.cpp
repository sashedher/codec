#include<iostream>
using namespace std;

void swap(int *p,int* q){
    int t;
    t=*p;*p=*q;*q=t;
}

int partition(int* C,int l,int h){
    int i,j,x;
    x=C[h];
    i=l-1;
    for(j=l;j<h;j++){
        if(C[j]<=x){
            i+=1;
            swap(C[i],C[j]);
        }
    }
    swap(C[i+1],C[h]);
    return i+1;
}

void sortQuick(int* B,int l,int h){
    int q;
    if(l<h){
        q=partition(B,l,h);
        sortQuick(B,l,q-1);
        sortQuick(B,q+1,h);
    }
}


void sortBub(int *B,int n){
    int flag,i,j;
    flag=0;
    for(i=n;i>0;i--){
        for(j=0;j<i-1;j++){
            if(B[j]>B[j+1]){
                swap(B[j],B[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
        
    }
}

void countfreq(int* B,int s){
    int i,c=1,x;                      //O(1)
    
    sortBub(B,s);                   //O(n^2)       //sorting array using Bubble sort for worst case running time complexity T(n)=O(n^2)
    x=B[0];
    for(i=1;i<s;i++){                 //O(n)
        if(x==B[i])                     
            c++;
        else{
            cout<<x<<"\t"<<c<<"\n";                     //printing element And its count
            c=1;
            x=B[i];                                     
        }
    }
    cout<<x<<"\t"<<c<<"\n";             //O(1)
}
                  //  total   T(n)=1+n^2+n+1=O(n^2)

int main(){
    int i,j,n=16,t,k;
    //cin>>n;
    //int * A=new int[n];
    int A[]={-12,3,-12,4,1,1,-12,1,-1,1,2,3,4,2,3,-12};
    for(i=0;i<n;i++){                                       //printing array before sorting
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    cout<<"N\tCount\n";
    countfreq(A,n);
    return 0;
}