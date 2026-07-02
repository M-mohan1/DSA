class Solution {
public:
    int ans ;
    void solve(int i,vector<int>&nums,int curr,int end,vector<int>&sums){
        if(i==end) {
            sums.push_back(curr);
            return ;
        }

        solve(i+1,nums,curr+nums[i],end,sums);
        solve(i+1,nums,curr,end,sums);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();

        vector<int>leftSum;
        vector<int>rightSum;

        solve(0,nums,0,n/2,leftSum);
        solve(n/2,nums,0,n,rightSum);

        sort(rightSum.begin(),rightSum.end());

        ans=INT_MAX;

        for(auto & x:leftSum){
            int target=goal-x;

            auto it = lower_bound(rightSum.begin(), rightSum.end(), target);
        
            if (it != rightSum.end()) {
                ans = min(ans, abs(goal - (x + *it)));
            }
    
            if (it != rightSum.begin()) {
                auto prev = it - 1;
                ans = min(ans, abs(goal - (x + *prev)));
            }

            if (ans == 0) return 0;
        }
        return ans ;

    }
};