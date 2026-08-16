#include<bits/stdc++.h>
using  namespace std ;

class Solution {
public:
    int dp[101][101][101][4];
    int n1, n2, n3;
    const int MOD = 1e9 + 7;

    long long solve(int i, int j, int k, int mask, string& w1, string& w2, string& target) {
        if (k == n3) {
            return (mask == 3) ? 1 : 0; 
        }

        if (dp[i][j][k][mask] != -1) {
            return dp[i][j][k][mask];
        }

        long long ways = 0;

        for (int next_i = i; next_i < n1; next_i++) {
            if (w1[next_i] == target[k]) {
                ways = (ways + solve(next_i + 1, j, k + 1, mask | 1, w1, w2, target)) % MOD;
            }
        }

        for (int next_j = j; next_j < n2; next_j++) {
            if (w2[next_j] == target[k]) {
                ways = (ways + solve(i, next_j + 1, k + 1, mask | 2, w1, w2, target)) % MOD;
            }
        }

        return dp[i][j][k][mask] = ways;
    }

    int interleaveCharacters(string word1, string word2, string target) {
        n1 = word1.length();
        n2 = word2.length();
        n3 = target.length();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, 0, 0, 0, word1, word2, target);
    }
};