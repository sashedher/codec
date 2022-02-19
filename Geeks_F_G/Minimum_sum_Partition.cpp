// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
 
#include<bits/stdc++.h>
using namespace std;
 

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int mn=INT_MAX,sm;
	    vector<int> ans;
	    vector<int> res(arr,arr+n);
	    
	    sm=accumulate(res.begin(),res.end(),0);
	    ans=Subsetsum(res,sm);
	    res.clear();
	    for(int i=0;i<ans.size();i++){
	        if(ans[i]==1) res.push_back(i);
	    }
	    for(int i=0;i<=res.size()/2;i++){
	        mn=min(mn,abs(sm-2*res[i]));
	    }
	    return mn;
    }
	vector<int> Subsetsum(vector<int>& nums, int sm){
	    vector<vector<int>> t(nums.size()+1,vector<int>(sm+1,0));
	    for(int i=0;i<=nums.size();i++){
	        t[i][0]=1;
	    }
	    for(int i=1;i<=nums.size();i++){
	        for(int j=1;j<=sm;j++){
	            if(nums[i-1]<=j){
	                t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
	            }
	            else t[i][j]=t[i-1][j];
	        }
	    }
	    return t[nums.size()];
	}
};

int main(){
	int A[]={68,35, 1, 70, 25,79, 59, 63, 65 ,6 ,46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70 ,13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45 };
	Solution op;
	cout<<op.minDifference(A,51)<<endl;
	return 0;
}