// https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1

// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int s=0,t=n;
        while(n>0){
            s=s+pow(n%10,3);
            n/=10;
        }
        if(s==t) return "Yes";
        else return "No";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends