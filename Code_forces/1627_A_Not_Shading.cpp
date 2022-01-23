// https://codeforces.com/contest/1627/problem/0    - solved
#include<bits/stdc++.h>
// #include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  

        int n,m,r,c,fl=0;
        cin>>n>>m>>r>>c;
        int a[n][m];
        char cl;
        vector<int> row(n),col(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>cl;
                if(cl=='W') a[i][j]=0;
                else {
                    a[i][j]=1;
                    row[i]=1;
                    col[j]=1;
                    fl=1;
                }
            }

        }
        if(a[r-1][c-1]==1) cout<<"0\n";
        else if((row[r-1]==1) || (col[c-1]==1)) cout<<"1\n";
        else if(fl==1) cout<<"2\n";
        else cout<<"-1\n";


    }
    return 0;
}
