// https://practice.geeksforgeeks.org/problems/print-the-kth-digit3520/1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int kthDigit(int A,int B,int K){
        
        // code here
        long long int s=pow(A,B);
        while(--K){
            s/=10;
        }
        return s%10;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int A,B,K;
        cin>>A>>B>>K;
        Solution ob;
        cout << ob.kthDigit(A,B,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends