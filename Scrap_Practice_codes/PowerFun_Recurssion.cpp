#include<iostream>
using namespace std;
/*use DP to reduce Time Complexity*/
int powe(int x,int y){
    if(y==0) return 1;
    if(y==1) return x;
    if(y%2==0) return powe(x,y/2)*powe(x,y/2);
    else return x*powe(x,y-1);
}
int main(){
    int x,y;
    cin>>x>>y;
    y=powe(x,y);
    cout<<y;
    return 0;
}