#include<iostream>
using namespace std;
template <typename t>
void  circularRightShift( t *x,int n){
    t t1;
    t1=x[n-1];
    for(int i=n-1;i>0;i--){
        x[i]=x[i-1];
    }
    x[0]=t1;
}
int main(){
    int A[6]={4,5,6,1,2,3};
    cout<<"Before shifting  :\t";
    for (int i = 0; i < 6; i++)
    {
     cout<<A[i]<<" ";
    }
    
    circularRightShift<int>(A,6);
    cout<<"\nAfter shifting  :\t";
    for (int i = 0; i < 6; i++)
    {
     cout<<A[i]<<" ";
    }
    string B[4]={"Jack","Jhon","Alice","Tom"};
    cout<<"\n\nBefore shifting  :\t";
    for (int i = 0; i < 4; i++)
    {
     cout<<B[i]<<" ";
    }
    circularRightShift<string>(B,4);
    cout<<"\nAfter shifting  :\t";
    for (int i = 0; i < 4; i++)
    {
     cout<<B[i]<<" ";
    }
    return 0;
}
