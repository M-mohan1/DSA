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
                
int N;
int LOG;
vector<vector<int>>adj;
vector<int>parent;
vector<vector<int>>dp;
vector<int>diff_array;
vector<int>depth;


void getDepth(int u, int par,int d){
    parent[u]=par;
    dp[u][0]=par;
    depth[u]=d;

    for(auto &v:adj[u]){
        if(v==par) continue;
        getDepth(v,u,d+1);
    }
}

void TreeAncester(){

    for(int i=0;i<N;i++){
        dp[i][0]=parent[i];
    }

    for(int j=1;j<LOG;j++){
        for(int v=0;v<=N;v++){
            if(dp[v][j-1]!=-1){
                dp[v][j]=dp[dp[v][j-1]][j-1];
            }
        }
    }
}

int getAncester(int u,int v){

    if(depth[u]<depth[v]) swap(u,v);

    int k=depth[u]-depth[v];

    for(int j=0;j<LOG;j++){
        if(k & (1<<j)){
            u=dp[u][j];
        }
    }

    if(u==v) return u;

    for(int j=LOG-1;j>=0;j--){
        if(dp[u][j]==-1)  continue;

        if(dp[u][j]!=dp[v][j]){
            u=dp[u][j];
            v=dp[v][j];
        }
    }

    return dp[u][0];
}


void dfs(int u, int par) {

    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u);
            diff_array[u] += diff_array[v];
        }
    }
}

void Testcases()
{
    int n,m;
    cin>>n>>m;
    
    adj.resize(n);
    parent.resize(n);
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    N=n;
    LOG=log2(n)+1;
    dp.assign(n+1,vector<int>(LOG,-1));
    depth.assign(n,0);

    getDepth(0,-1,0);
    TreeAncester();

    diff_array.assign(n,0);

    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        int LCA=getAncester(u,v);
        diff_array[u]++;
        diff_array[v]++;
        diff_array[LCA]--;
        if(parent[LCA]!=-1) diff_array[parent[LCA]]--;

    }

    dfs(0,-1);
    for(int i=0;i<n;i++){
        cout<<diff_array[i]<<" ";
    }

    cout<<"\n";
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