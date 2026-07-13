#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    int cols;
    const int MOD=1e9+7;

    vector<vector<int>>adj;
    vector<int>depth;
    vector<vector<int>>dp;

    void dfs(int node,int parent){
        dp[node][0]=parent;

        for(auto &it:adj[node]){
            if(it==parent) continue;

            depth[it]=depth[node]+1;
            dfs(it,node);
        }
    }


    void fillDp(){

        for(int j=1;j<cols;j++){
            for(int node=0;node<n;node++){
                if(dp[node][j-1]!=-1){
                    dp[node][j]=dp[dp[node][j-1]][j-1];
                }
            }
        }
    }

    int findLca(int u,int v){
        if(depth[u]<depth[v]) swap(u,v);

        int k=depth[u]-depth[v];

        for(int j=0;j<cols;j++){
            if(k & (1<<j)){
                u=dp[u][j];
            }
        }

        if(u==v) return u;

        for(int j=cols-1;j>=0;j--){
            if(dp[u][j]==-1)  continue;

            if(dp[u][j]!=dp[v][j]){
                u=dp[u][j];
                v=dp[v][j];
            }
        }

        return dp[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        n=edges.size()+1;
        cols=log2(n)+1;

        adj.resize(n);

        for(auto &it:edges){
            int u=it[0]-1;
            int v=it[1]-1;
            adj[u].push_back(v); 
            adj[v].push_back(u); 
        }
        dp.assign(n+1,vector<int>(cols+1,-1));

        depth.assign(n,0);
        dfs(0,-1);


        fillDp();

        vector<int>pow2(n+1);
        pow2[0]=1;

        for(int i=1;i<=n;i++){
            pow2[i]=(2LL*pow2[i-1])%MOD;
        }

        vector<int>ans;

        for(auto &it:queries){
            int u=it[0]-1;
            int v=it[1]-1;

            int lca=findLca(u,v);
            int d=depth[u]+depth[v]-2*depth[lca];

            if(d==0) ans.push_back(0);
            else ans.push_back(pow2[d-1]);
        }

        return ans;

    }
};