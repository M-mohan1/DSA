#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& nums,int mask) {
        if(mask== (1<<n)-1) return 0;

        if(dp[mask]!=-1) return dp[mask];
        int op = __builtin_popcount(mask) / 2 + 1;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) continue;

            for (int j = i + 1; j < n; j++) {
                if (mask & (1<<j)) continue;

                int newmask= mask | (1<<j) | (1<<i);
                ans=max(ans,op*__gcd(nums[i],nums[j])+solve(nums,newmask));
            }
        }

        return dp[mask]=ans;
    }

    int maxScore(vector<int>& nums) {
        n=nums.size();
        dp.assign(1<<n,-1);
        return solve(nums,0);
    }
};