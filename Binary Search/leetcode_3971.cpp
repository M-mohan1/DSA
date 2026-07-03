
// nice problem on binary search on threshold  with arithmetic decay 
// similer problem  leetcode 1648 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    const int mod=1e9+7;
    int n;
    long long count(vector<int>& value, long long x,vector<int>&decay,int m) {
        long long cnt = 0;

        for (int i=0;i<n;i++) {
            if (value[i] >= x) {
                cnt += 1+(value[i]-x)/(decay[i])  ;  
                if (cnt >= m) return cnt;
            }
        }

        return cnt;
    }

    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        n=value.size();
        int l=1;
        int h=0;

        for(int i=0;i<n;i++){
            h=max(h,value[i]);
        }

        while(l<=h){
            int mid=l+(h-l)/2;
            if(count(value,mid,decay,m)>=m){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }

        long long  threshold=h;
        long long total=0;
        long long  ans =0;

        for (int i=0;i<n;i++) {

            if (value[i] < threshold) continue;

            long long cnt = (value[i] - threshold) / decay[i] + 1;

            long long last = value[i] - (cnt - 1LL) * decay[i];

            long long sum = cnt * (value[i] + last) / 2;

            total += cnt;
            ans = (ans + sum) % mod;
        }

        long long extra = total - m;

        ans = (ans - extra % mod * (threshold % mod)) % mod;

        if (ans < 0) ans += mod;

        return ans;
    }
};