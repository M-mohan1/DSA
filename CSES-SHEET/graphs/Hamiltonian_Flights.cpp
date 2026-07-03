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
                
void Testcases()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
    }

    vector<vector<ll>>dp(1<<n,vector<ll>(n,0));
    dp[1<<0][0]=1; //  dp[mask][u] number of ways to reach at vertex u from vertex 0 by visiting  exactly mask vertices 

    for(int mask=0;mask<(1<<n);mask++){
        for(int u=0;u<n;u++){
            if((mask & (1<<u)) ==0) continue;

            ll ways=dp[mask][u];
            if(ways==0) continue;
            for(auto &v:adj[u]){
                if((mask & (1<<v)) != 0) continue;
                int newmask=   mask |(1<<v);
                dp[newmask][v]=(dp[newmask][v]+ways)%mod;
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1]%mod<<"\n";
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