/*
If someone has achieved it before, it means it's possible.
Every accepted solution was once a wrong answer.
The expert in anything was once a beginner.
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define rev(v) reverse(all(v))

#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                
int cycle_len;
int start;
vector<int>dist; // dist from dfs start node to u;
void dfs(int u,vector<int>&g,vector<int>&dp,vector<int>&vis,int curr_dist){
    if(vis[u]) return;
    vis[u]=1;
    dist[u]=curr_dist;

    int v=g[u];
    if(!vis[v]) dfs(v,g,dp,vis,curr_dist+1);
    else{
        if(dp[v]==0) {
            cycle_len=dist[u]-dist[v]+1;
            start=v;
        }
        else cycle_len=dp[v];
    }

    if(start!=-1){
        dp[u]=cycle_len;
        if(u==start) start=-1;
    }
    else{
        dp[u]=dp[v]+1;
    }

}
void Testcases()
{
    int n;
    cin>>n;

    vector<int>graph;
    f(i,0,n){
        int u;
        cin>>u;
        --u;
        graph.push_back(u);
    }

    vector<int>dp(n,0);  // d[u]=number of ways when start from vertex u;
    vector<int>vis(n,0);
    dist.assign(n,0);
    f(i,0,n){
        if(vis[i]==0) {
            start=-1;
            cycle_len=0;
            dfs(i,graph,dp,vis,1);
        }
    }

    for(auto x:dp) cout<<x<<" ";
}
int main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        Testcases();
    }
}