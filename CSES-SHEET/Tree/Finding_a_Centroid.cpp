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
vector<vector<int>>adj;
vector<int>Size;

void dfs_sz(int u,int parent){
    Size[u]=1;
    for(auto &v:adj[u]){
        if(v==parent) continue;
        dfs_sz(v,u);
        Size[u]+=Size[v];

    }
}

int get_centroid(int u,int parent){

    for(auto &v:adj[u]){
        if(v!=parent && Size[v]>N/2){
            return get_centroid(v,u);
        }
    }
    return u;
}

void Testcases()
{
    int n;
    cin>>n;
    N=n;

    adj.resize(n);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Size.resize(n);

    dfs_sz(0,-1);
    cout<<get_centroid(0,-1)+1<<"\n";

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