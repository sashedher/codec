#include<iostream>
using namespace std;
int main(){
    int a[6][6],i,j,b[4][4],s=-81;
    for(i=0;i<6;i++){
        for(j=0;j<6;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            b[i][j]=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                if(s<b[i][j])
                    s=b[i][j];
        }
    }
    cout<<s;
    return 0;
}