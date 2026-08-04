#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(int idx,int end,vector<int>&rods,int left,int right,unordered_map<int,int>&mp){
        if (idx == end) {
            int diff = left - right;
            int smaller = min(left, right);

            if (mp.find(diff) == mp.end())
                mp[diff] = smaller;
            else
                mp[diff] = max(mp[diff], smaller);

            return;
        }

        solve(idx+1,end,rods,left+rods[idx],right,mp);

        solve(idx+1,end,rods,left,right+rods[idx],mp);

        solve(idx+1,end,rods,left,right,mp);
    }

    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();

        unordered_map<int,int>leftSum,rightSum;

        solve(0,n/2,rods,0,0,leftSum);
        solve(n/2,n,rods,0,0,rightSum);

        int ans=0;

        for(auto &it:leftSum){
            int diff=it.first;
            int smaller1=it.second;

            if(rightSum.count(-diff)){
                ans=max(ans,smaller1 + rightSum[-diff] + abs(diff));
            }
        }

        return ans ;
    }
};

