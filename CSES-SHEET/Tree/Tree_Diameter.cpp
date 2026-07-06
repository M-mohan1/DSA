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
                
int ans ;
vector<vector<int>>adj;

int dfs(int u,int parent){

    int mx1 = 0, mx2 = 0;

    for (int v : adj[u]) {
        if (v == parent) continue;

        int d = dfs(v, u) + 1;

        if (d >= mx1) {
            mx2 = mx1;
            mx1 = d;
        } else if (d > mx2) {
            mx2 = d;
        }
    }

    ans = max(ans, mx1 + mx2);
    return mx1;
}

void Testcases()
{
    int n;
    cin>>n;

    adj.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
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