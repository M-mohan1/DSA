#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n =colors.size();

        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int>topo;
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            topo.push_back(u);

            for(auto & v:adj[u]){
                indegree[v]--;

                if(indegree[v]==0) q.push(v);
            }
        }

        if(topo.size()!=n) return -1;

        vector<vector<int>> dp(n, vector<int>(26, 0));

        for(int i=n-1;i>=0;i--){
            int u = topo[i];

            for(int v: adj[u]){
                for(int c=0;c<26;c++)
                    dp[u][c] = max(dp[u][c], dp[v][c]);
            }

            dp[u][colors[u]-'a']++;
        }

        int ans = 0;
        for(int i=0;i<n;i++)
            for(int c=0;c<26;c++)
                ans = max(ans, dp[i][c]);

        return ans;
    }
};