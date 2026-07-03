
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    vector<int>result;
    int dp[20001][4];

    int helper(int idx,int count,vector<int>&sums,int k){
        if(count==0) return 0;
        if(idx>=n) return INT_MIN;

        if(dp[idx][count]!=-1) return dp[idx][count];

        int take=sums[idx] + helper(idx+k,count-1,sums,k);
        int not_take=helper(idx+1,count,sums,k);

        return dp[idx][count]=max(take,not_take);
    }
    void solve(int idx,vector<int>&sums,int k,int count){
        if(count==0) return ;
        if(idx>=n) return ;

        int take= sums[idx]+ helper(idx+k,count-1,sums,k);
        int not_take=helper(idx+1,count,sums,k);

        if(take>=not_take){
            result.push_back(idx);
            solve(idx+k,sums,k,count-1);
        }
        else{
            solve(idx+1,sums,k,count);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        vector<int> sums;
        int windowSum = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            windowSum += nums[j];
        
            if (j - i + 1 == k) {
                sums.push_back(windowSum); 
                windowSum -= nums[i];     
                i++;
            }
            j++;
        }

        n=sums.size();
        memset(dp,-1,sizeof(dp));

        solve(0,sums,k,3);

        return result;

    }
};