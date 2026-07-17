#include<bits/stdc++.h>
using namespace std;

// same approach as CF-2244G;
// use segment tree to get max from previouds seen indices 
// see edge cases carefully  in query function . segment tree on values this time not on indices .


class SegTree{
public:
    using ll=long long ;

    int n;
    vector<ll>tree;

    SegTree(int n){
        this->n=n;
        tree.assign(4*n,0LL);
    }

    void update(int idx,int l,int r,int pos,ll val){
        if(l==r){
            tree[idx]=max(tree[idx],val);
            return ;
        }

        int mid=(l+r)/2;

        if(pos<=mid){
            update(2*idx+1,l,mid,pos,val);
        }
        else update(2*idx+2,mid+1,r,pos,val);

        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void update(int pos, ll val) {
        update(0, 0, n - 1, pos, val);
    }


    ll query(int idx,int l,int r,int q1,int q2){

        if(r<q1 || l>q2) return 0LL;
        if (q1 <= l && r <= q2) return tree[idx];

        int mid=(l+r)/2;
        ll p1=query(2*idx+1,l,mid,q1,q2);
        ll p2=query(2*idx+2,mid+1,r,q1,q2);

        return max(p1,p2);
    }

    ll query(int q1, int q2) {
        q1 = max(0, q1); 
        
        if (q1 > q2) return 0LL;
        return query(0, 0, n - 1, q1, min(q2, n - 1));
    }
};
class Solution {
    using ll=long long ;
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();

        int mx=*max_element(nums.begin(),nums.end());
        SegTree st(mx+1);
        vector<ll>dp(n,0);

        ll ans=0;

        for(int i=0;i<n;i++){

            ll max_prev=st.query(nums[i]-k,nums[i]-1);

            dp[i]=max(dp[i],max_prev+1);
            ans=max(ans,dp[i]);

            st.update(nums[i],dp[i]);
        }

        return ans ;
    }

};

