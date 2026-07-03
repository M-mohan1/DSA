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
                
void dfs(int u,vector<vector<int>>&adj,vector<bool>&vis){
    if(vis[u]==true) return ;
    vis[u]=true;
    for(auto &v:adj[u]){
        if(!vis[v]) dfs(v,adj,vis);
    }
}
void Testcases()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    vector<vector<int>>rev_adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    vector<bool>vis(n,0);
    dfs(0,adj,vis);

    f(i,0,n){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<1<<" "<<i+1<<"\n";
            return ;
        }
    }

    f(i,0,n) vis[i]=0;

    dfs(0,rev_adj,vis);

    f(i,0,n){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<i+1<<" "<<1<<"\n";
            return ;
        }
    }
    cout<<"YES\n";
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