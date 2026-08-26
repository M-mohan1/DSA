/*
multistage dp 
new approach 
vivek gupta specific lecture 
*/

#include<bits/stdc++.h>
using namespace  std ;

// memoization :-
class Solution {
public:
    int n;
    int solve(int i,int prev,string &s,vector<vector<int>>&dp){
        if(i==n) return 0;

        if(dp[i][prev]!=-1) return dp[i][prev];

        int ans =1e6;

        for(int k=prev;k<=2;k++){
            if(k==1){
                if(s[i]=='0') ans=min(ans,solve(i+1,k,s,dp));
                else ans=min(ans,solve(i+1,k,s,dp)+2);
            }
            else ans=min(ans,solve(i+1,k,s,dp)+1);
        }

        return dp[i][prev] = ans ;
    }

    int minimumTime(string s) {
        n=s.size();

        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(0,0,s,dp);
    }
};

// tabulation :-
class Solution {
public:
    int n;

    int minimumTime(string s) {
        n=s.size();

        vector<vector<int>>dp(n+1,vector<int>(3,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=2;j++){
                int ans =1e6;

                for(int k=j;k<=2;k++){
                    if(k==1){
                        if(s[i]=='0') ans=min(ans,dp[i+1][k]);
                        else ans=min(ans,dp[i+1][k]+2);
                    }
                    else ans=min(ans,dp[i+1][k]+1);
                }

                dp[i][j]=ans ;
            }
        }

        return min({dp[0][0],dp[0][1],dp[0][2]});
    }
};

// space optimization :-
class Solution {
public:
    int minimumTime(string s) {
        int n = s.size();

        vector<int> next(3, 0);

        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur(3);

            for (int j = 0; j < 3; j++) {
                int ans = 1e6;

                for (int k = j; k <= 2; k++) {
                    if (k == 1) {
                        if (s[i] == '0')
                            ans = min(ans, next[k]);
                        else
                            ans = min(ans, next[k] + 2);
                    } else {
                        ans = min(ans, next[k] + 1);
                    }
                }

                cur[j] = ans;
            }

            next = cur;
        }

        return min({next[0], next[1], next[2]});
    }
};