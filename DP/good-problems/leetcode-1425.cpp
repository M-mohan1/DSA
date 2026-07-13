// memoization using map and bottom-up gives TLE ;
// use max Heap for get max in a range in log(n);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>dp(n);
        
        for(int i=0;i<n;i++){
            dp[i]=nums[i];
        }

        int result=dp[0];

        priority_queue<pair<int,int>>pq;
        pq.push({dp[0],0});

        for(int i=1;i<n;i++){

            while(!pq.empty() && i-pq.top().second>k){
                pq.pop();
            }

            dp[i]=max(dp[i],nums[i]+pq.top().first);
            pq.push({dp[i],i});

            result=max(result,dp[i]);
        }

        return result;
    }
};