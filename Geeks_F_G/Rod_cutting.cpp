//  https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#
 
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> t(n+1, vector<int>(n+1,0));
        vector<int> len(n);
        for(int i=1;i<=n;i++){
            len[i-1]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(len[i-1]<=j){
                    t[i][j]=max(t[i-1][j] , (price[i-1]+t[i][j-len[i-1] ]) );
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[n][n];
    }
};

int main(){
    Solution op;
    int price[]={3, 5, 8, 9, 10, 17, 17, 20};
    cout<<op.cutRod(price,8)<<endl;
    return 0;
}