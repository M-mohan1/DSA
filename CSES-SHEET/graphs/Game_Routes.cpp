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
                
int n;
int solve(int u,vector<vector<int>>&adj,vector<int>&dp){

    if(u==n-1) return 1;
    if(dp[u]!=-1) return dp[u];

    ll take=0;
    for(auto &it:adj[u]){
        take=(take+solve(it,adj,dp))%mod;
    }
    return dp[u]=take%mod;
}
void Testcases()
{
    int m;
    cin>>n>>m;

    vector<vector<int>>adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;

        --u;
        --v;
        adj[u].push_back(v);
    }

    ll  ans=0;
    vector<int>dp(n+1,-1);
    ans=solve(0,adj,dp)%mod;
    cout<<ans<<"\n";
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