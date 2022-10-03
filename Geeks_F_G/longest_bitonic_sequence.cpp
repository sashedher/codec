

#include<bits/stdc++.h>
using namespace std;

	
	int LongestBitonicSequence(vector<int>nums){
	    int n=nums.size();
	    vector<int> dp(n,1),dp2(n,1);
	    int res=INT_MIN;
	    for(int i=0;i<n;i++){
            for(int pr=0;pr<i;pr++){
                if(nums[pr]<nums[i]){
                    dp[i]=max(dp[i],1+dp[pr]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int pr=n-1;pr>i;pr--){
                if(nums[pr]<nums[i]){
                    dp2[i]=max(dp2[i],1+dp2[pr]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            res=max(res, dp[i]+dp2[i]-1);
        }
        return res;
	}
