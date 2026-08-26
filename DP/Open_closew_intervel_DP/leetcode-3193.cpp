// we are calculating interval  either by adding  > i , < i and inverson follow a pattern = int newiv=i+1-ch;
// something new

#include<bits/stdc++.h>
using namespace  std ;

class Solution {
public:
    const int mod=1e9+7;
    vector<int>posreq;

    int dp[301][401];

    int solve(int i,int k,int n){

        if(posreq[i]!=-1 && posreq[i]!=k) return 0;

        if(i==n-1) return 1;

        if(k>400) return 0;

        if(dp[i][k]!=-1) return dp[i][k];

        int ans =0;
        for(int ch=0;ch<=i+1;ch++){
            int newiv=i+1-ch;
            ans=(ans+solve(i+1,k+newiv,n))%mod;
        }

        return dp[i][k]=ans%mod ;
    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        posreq.assign(n,-1);

        for(auto &v:requirements){
            posreq[v[0]]=v[1];
        }

        memset(dp,-1,sizeof(dp));

        return solve(0,0,n);
    }
};