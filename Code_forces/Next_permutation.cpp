#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v={1,2,354,4};
    int c=0;
    do{
        c++;
        for(auto x:v) cout<<x<<" ";
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    
    cout<<c<<endl;
    return 0;

}
