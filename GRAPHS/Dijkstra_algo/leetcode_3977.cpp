#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    using ll=long long ;
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges,
                                    int power, vector<int>& cost,
                                    int source, int target) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
        }

        priority_queue<tuple<ll ,ll ,int>> pq;

        vector<vector<ll >> dist(n+1, vector<ll>(power+1,LLONG_MAX));
        dist[source][power] = 0;
        pq.push({0,power,source});

        while(!pq.empty()){
            auto [time,currPower,u] = pq.top();
            time*=-1;
            pq.pop();
            if(u == target){
                return {time,currPower};
            }
            if(time>dist[u][currPower])continue;

            if(currPower<cost[u])continue;
            for(const auto [v,w] :adj[u]){
                ll newPower = currPower-cost[u] , newT = time+w;
                if(dist[v][newPower] >newT){
                    dist[v][newPower] = newT;
                    pq.push({-newT,newPower,v});
                }
                
            }
        }
        return {-1,-1};
        }
};