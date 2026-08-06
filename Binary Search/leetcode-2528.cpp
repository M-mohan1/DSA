#include<bits/stdc++.h>
using namespace std;

// difference array + binary search 
class Solution {
public:
    using ll=long long;

    bool check(ll  mid, vector<ll >&dp, int r, int k, int n) {
        vector<ll> tempDiff = dp;

        ll  cumSum = 0; 

        for(int i = 0; i < n; i++) {
            cumSum += tempDiff[i];

            if(cumSum < mid) {
                ll need = mid - cumSum;
                if(need > k) {
                    return false;
                }

                k -= need;
                cumSum += need; 

                if(i + 2*r + 1 < n)
                    tempDiff[i+2*r+1] -= need; 
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();

        vector<ll>dp(n,0);

        for(int i=0;i<n;i++){
            dp[max(0,i-r)]+=stations[i];

            if(i+r+1<n){
                dp[i+r+1]-=stations[i];
            }
        }

        ll l=*min_element(stations.begin(),stations.end());
        ll h=accumulate(stations.begin(),stations.end(),0LL);
        h+=k;


        ll ans =l;

        while(l<=h){
            ll mid=l+(h-l)/2;

            if(check(mid,dp,r,k,n)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        } 

        return ans;
    }
};