#include<iostream>
#include<string.h>
using namespace std;
int main(){
    cout<<"hello World\n";

    string s;
    getline(cin,s);
    int a[26]={0};
    for(int i=0;i<s.length();i++){
        a[s[i]-'A']++;
    }
    for(int i=0; i<26;i++){
        cout<<(char)('A'+i)<<" - "<<a[i]<<" - "<<(float)a[i]/s.length()*100<<"\n";
    }

    
    return 0;

}