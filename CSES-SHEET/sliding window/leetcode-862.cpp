#include<bits/stdc++.h>
using  namespace std ;

class Solution {
public:
    using ll= long long ;
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();

        deque<int>dq;
        vector<ll>dp(n+1,0);

        for(int i=0;i<n;i++){
            dp[i+1] = dp[i]+nums[i];
        }

        int ans =n+1;

        for(int i=0;i<=n;i++){
            while(!dq.empty() && dp[i]-dp[dq.front()] >=k){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && dp[i] <= dp[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return ans == n+1 ? -1 : ans;
    }
};