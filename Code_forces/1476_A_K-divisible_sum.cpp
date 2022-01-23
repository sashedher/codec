#include<iostream>
using namespace std;
int main(){
   long long int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        if(n>k){
            if(n%k==0) cout<<"1\n";
            else cout<<"2\n";
        }
        else{
            if(k%n==0) cout<<k/n<<endl;
            else cout<<k/n+1<<endl;
        }
    }
    return 0;
}