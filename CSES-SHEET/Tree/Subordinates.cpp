#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;
#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define printcount cout<<count<<endl;
#define i_n int i=0;i<n;i++
#define f(i, a, b) for (int i = a; i < b; i++)

vector<int>ans;

void dfs(int u, vector<vector<int>>& adj, int par){

    int cnt = 0;

    for(auto child : adj[u]){

        if(child == par) continue;

        dfs(child, adj, u);

        cnt += 1 + ans[child];
    }

    ans[u] = cnt;
}
void solve()
{
    int n;
    cin>>n;

    iv(a,n-1);
    ans.resize(n,0);

    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
        adj[a[i]-1].push_back(i+1);
        adj[i+1].push_back(a[i]-1);
    }

    dfs(0,adj,-1);

    for(auto &it:ans) cout<<it<<" ";
    cout<<"\n";
}
int main()
{
    fast_io;
    int tt=1;
    //cin >> tt;
    while(tt--)
    {
        solve();
    }
}