// https://leetcode.com/problems/distribute-candies-to-people/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int c=0;
            for(int i=0;candies>0;i++){
                c++; 
                if(c>candies) c=candies;                    // distribute remaining all candiates to final one if capacity c > remaining candies  
                res[i%num_people]+=c;
                candies-=c;
                
                
            }
        
        return res;
    }
};