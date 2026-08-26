// intervel dp .
// first do leetcode 3193 , then this with an optimization by removing inner for loop .

#include<bits/stdc++.h>
using namespace  std ;

class Solution {
public:
    const int mod=1e9+7;

    int kInversePairs(int n, int k) {

        vector<vector<int>> dp(n + 1, vector<int>(k + 2, 0));

        dp[n-1][k] = 1;

        for (int i = n-2; i >=0; i--) {

            for (int j = k; j >=0; j--) {

                int remove = 0;

                if (j + i + 2 <= k) {
                    remove = dp[i + 1][j + i + 2];
                }

                dp[i][j] = (dp[i][j] + dp[i][j+1] + dp[i+1][j] - remove)%mod;

                if (dp[i][j] < 0)
                    dp[i][j] += mod;
            }
        }

        return dp[0][0];
    }
};