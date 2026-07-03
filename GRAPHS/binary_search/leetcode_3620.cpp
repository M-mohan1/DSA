//Approach-1 (binary search + dijkstra)
//T.C : O((E+V)logVlogmx)
//S.C : O(V+E)

// leetcode editorial =https://leetcode.com/problems/network-recovery-pathways/editorial/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll=long long ;
    vector<vector<pair<int,int>>>adj;
    int n;

    bool check(int mid,ll k){

        vector<ll>dist(n,LLONG_MAX);
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>pq;

        pq.push({0,0});
        dist[0]=0;

        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();

            if (d > k) {
                return false;
            }
            if (u == n - 1) {
            return true;
            }

            if(dist[u]<d) continue;

            for(auto &it:adj[u]){
                int v=it.first;
                int cost=it.second;

                if(cost<mid) continue;

                if(dist[v]>d+cost){
                    dist[v]=d+cost;
                    pq.push({dist[v],v});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n=online.size();

    adj.resize(n);
    int l=INT_MAX;
    int r=0;

    for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        int cost=it[2];

        if (!online[u] || !online[v]) {
                continue;
        }

        l=min(l,cost);
        r=max(r,cost);
        adj[u].push_back({v,cost});
    }

    if (!check(l,k)) {
            return -1;
        }


    while(l<=r){
        int mid=l+(r-l)/2;

        if(check(mid,k)){
            l=mid+1;
        }
        else r=mid-1;
    }
    return r ;
    }
};

int main(){
    return 0;
}

//Approach-2 (binary search + dfs)
//T.C : O((V+E)logmx)
//S.C : O(V+E)

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                        long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> g(n);
        int l = INT_MAX, r = 0;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (!online[u] || !online[v]) {
                continue;
            }
            g[u].push_back({v, w});
            l = min(l, w);
            r = max(r, w);
        }

        auto check = [&](int mid) -> int {
            vector<long long> memo(n, -1);
            auto dfs = [&](this auto&& dfs, int u) -> long long {
                if (u == n - 1) {
                    return 0;
                }
                if (memo[u] != -1) {
                    return memo[u];
                }
                long long res = LLONG_MAX / 2;
                for (auto& [v, w] : g[u]) {
                    if (w >= mid) {
                        res = min(res, dfs(v) + w);
                    }
                }
                memo[u] = res;
                return memo[u];
            };
            return dfs(0) <= k;
        };

        if (!check(l)) {
            return -1;
        }

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};