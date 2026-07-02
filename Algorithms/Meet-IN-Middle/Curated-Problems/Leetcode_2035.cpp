#include <bits/stdc++.h>
using namespace std;

    void solve(int i,vector<int>&nums,int curr,int end,vector<vector<int>>&sums,int k){
        if(i==end) {
            sums[k].push_back(curr);
            return ;
        }

        solve(i+1,nums,curr+nums[i],end,sums,k+1);
        solve(i+1,nums,curr,end,sums,k);
    } 

    int minimumDifference(vector<int>& nums) {
        int k=nums.size();
        int n=k/2;
        int total=accumulate(nums.begin(),nums.end(),0);

        vector<vector<int>>leftSum(n+1);
        vector<vector<int>>rightSum(n+1);

        solve(0,nums,0,n,leftSum,0);
        solve(n,nums,0,k,rightSum,0);

        for(int i=0;i<=n;i++){
            sort(rightSum[i].begin(),rightSum[i].end());
        }

        int ans=INT_MAX;
        for(int k=0;k<=n;k++){
            for(auto & sum:leftSum[k]){

                int required=(total-2*sum)/2;
                int idx=n-k;
                auto it=lower_bound(rightSum[idx].begin(),rightSum[idx].end(),required);

                if(it!=rightSum[idx].end()) ans = min(ans, abs(total-2*(sum+(*it))));

                if(it != rightSum[idx].begin()){
                    auto itr = prev(it);
                    ans = min(ans, abs(total-2*(sum+(*itr))));
                }
            }
        }

        return ans ;
    }

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums={1,2,5,6,3,4,6};
    cout<<minimumDifference(nums)<<"\n";

    return 0;
}
