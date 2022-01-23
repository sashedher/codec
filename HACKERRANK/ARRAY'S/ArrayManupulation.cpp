#include<iostream>
using namespace std;
int main(){
   long long int a,b,k,i,n,m,s=0,max=0;
    cin>>n;
    long long int *ar=new long long int[n+1]();               //  ()  constructor calling and default intialization is value zero for integers
    cin>>m;
    for(i=0;i<m;i++){
        cin>>a>>b>>k;
        ar[a]+=k;
        if(b+1<=n)   ar[b+1]-=k;
    }
    for(i=1;i<=n;i++){
        s+=ar[i];
        if(s>max)
            max=s;
    }
    cout<<max;
    return 0;
}/*adding sum to a[p] and adding negative sum at a[q+1].
 which make sure that when you add element from a[p] to a[q] sum is added only once and it should be subtracted at a[q+1] as this sum span from p to q only.
 Rest array element are either 0 or some other input sum. max of addition will be output*/
 //mario height
 