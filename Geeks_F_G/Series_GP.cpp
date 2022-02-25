// https://practice.geeksforgeeks.org/problems/series-gp4646/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long int m=1e9+7;
	long long int modPow(int r,int n){
	    if(n==0) return 1;
	   
	    long long int t= modPow(r,n/2) % m ;
	    t=(t*t)%m;
	    if(n%2==0) { 
	        return t;
	    }
	    else return (r*t) % m;
	}
   	int Nth_term(int a, int r, int n){
   	    // Code here
   	    return (a*modPow(r,n-1) )% m;
   	}    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends