#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    
    vector<vector<int>>dp;
    int LOG;
    int N;

    TreeAncestor(int n, vector<int>& parent) {
        N=n;
    LOG=log2(n)+1;
        dp.assign(n+1,vector<int>(LOG,-1));

        for(int root=0;root<n;root++){
        dp[root][0]=parent[root];
        }


        for (int j = 1; j < LOG; j++){
            for (int v = 0; v <= n; v++){
                if (dp[v][j-1] != -1)
                    dp[v][j] = dp[dp[v][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        LOG=log2(N)+1;

        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = dp[node][j];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */