#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int t,n,i,j,x;
    cin>>t;
    while(t--){
        //cin>>n;
        string s,w,tp;
        getline(cin,s);
        j=s.length();
        int* a= new int[j]{};
        x=stoi(s);
        cout<<j<<" "<<x<<"\n";
        cout<<"print";

        for(i=j-1;i>=0;i--){
            a[i]=x%10;
            x=x/10;
        }
        for(i=0;i<j;i++){
            cout<<a[i]<<" ";
        }
        delete[] a;
        
    }
    return 0;
}
/*char* s=new char[x];
        char* w=new char[n];
        char* tp=new char[n];*/