
/*
good implimentation of BIT .
take care of 1 base indexing in BIT .
how peaks affect each other .
when to update what .
*/

#include<bits/stdc++.h>
using namespace  std ;

class Solution {
public:

using ll=long long ; 

struct fenwick{
    int n;
    vector<ll>bit;

    fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }

    void update(int idx,int val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx & (-idx));
        }
    }

    ll query(int idx){
        ll sum =0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx & (-idx));
        }

        return sum ;
    }

    ll query_range(int l,int r){
        return query(r)-query(l-1);
    }
};
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n =nums.size();
        vector<int>dp(n,0);

        auto check_peak = [&](int i){
            if(i >= 1 && i <= n - 2){
                if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return 1;
            }
            return 0;
        };


        fenwick ft(n);

        for(int i=1;i<=n;i++){
            if(check_peak(i-1)){
                ft.update(i, 1);
                dp[i-1] = 1;
            }
        }

        vector<int>ans ;

        for(auto &it:queries){
            int type=it[0];
            int l=it[1];
            int r=it[2];

            if(type==1){
                if(r-l<2) ans.push_back(0);
                else ans.push_back(ft.query_range(l+2,r));
            }
            else{
                if(nums[l]==r) continue ;

                nums[l]=r;

                int st=max(1,l-1);
                int end=min(n-1,l+1);

                for(int i=st;i<=end;i++){
                    int nw=check_peak(i);
                    int diff=nw-dp[i];

                    if(diff!=0){
                        dp[i]=nw;
                        ft.update(i+1,diff);
                    }
                }
            }
        }

        return ans ;
    }
};