#include<iostream>
using namespace std;
int main(){

    // for(int i=0;i<10;i++){
    //     cout<<11*i+7<<" "<<17*i+13<<" "<<19*i+15<<endl;
    // }
    cout<<7*13*15<<endl;
    // for(int i=0;i<30;i++){
    //     cout<<(1365*i)%11<<" "<<(1365*i)%17<<" "<<(1365*i)%19<<endl;
    // }
    for(long long int i=0;i<2147483647;i++){
        
        if(i%11==7 && i%17==13 && i&19==15){
            cout<<i<<" "<<i%23;
            cout<<"found i"<<endl;
        }
    }
    for(int i=0;i<200;i++){
        cout<<(i*23+19)<<" \n";
    }
    cout<<endl;
    cout<<"Program Exited"<<endl;
    return 0;
}