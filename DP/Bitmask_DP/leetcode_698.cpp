#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    int target;
    int n;
    int dp[(1<<16)-1];
    bool solve(vector<int>&nums,int mask,int currSum ){
        if(mask==(1<<n)-1) return currSum==0;

        if(dp[mask]!=-1) return dp[mask];

        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {

                if (currSum + nums[i] > target)
                    continue;

                int newSum = (currSum + nums[i]) % target;

                if (solve(nums, mask | (1 << i), newSum))
                    return dp[mask] = 1;
            }
        }

        return dp[mask] = 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%k!=0) return false;
        target=sum/k;

        memset(dp,-1,sizeof(dp));
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>target) return false;

        return solve(nums,0,0);
    }
};