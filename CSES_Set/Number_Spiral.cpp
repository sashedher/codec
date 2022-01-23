#include<iostream>
using namespace std;
/*recurssion failed (Time_out):solve t(n)=t(n-1)+2*(n-1)  and use result_formuley for calculating diagonal elements */
int main(){
    long long  int t,x,y,b,n,i;
    cin>>n;
    long long int** A = new long long int*[n];
	for (i = 0; i < n; i++){
		A[i] = new  long long int[2];
    }
    for(i=0;i<n;i++){
        cin>>A[i][0]>>A[i][1];            
    }
    for(i=0;i<n;i++){
        x=A[i][0];
        y=A[i][1];
        t=(x>y)?x:y;
        b=t*(t-1)+1;
        if(x==y)    cout<<b<<"\n";
        else if(t%2==0) cout<<b+x-y<<"\n";
        else cout<<b+y-x<<"\n"; 
    }
    for (i = 0; i < n; i++){
		delete[] A[i];
    }
	delete[] A;
    return 0;
}