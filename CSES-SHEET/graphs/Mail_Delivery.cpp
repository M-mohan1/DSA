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
                

void getpath(int u,vector<vector<pair<int,int>>>&adj,vector<int>&path,vector<bool>&vis){
    int n = adj.size();

    while(!adj[u].empty()){
        auto [v,id]=adj[u].back();
        adj[u].pop_back();
        if(vis[id]==true) continue;
        vis[id]=true;
        getpath(v,adj,path,vis);
    }
    path.push_back(u);
}

void Testcases()
{
    int n,m;
    cin>>n>>m;
    int M=m;
    vector<vector<pair<int,int>>>adj(n);
    vector<int>degree(n,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        degree[u]++;
        degree[v]++;
    }

    f(i,0,n){
        if(degree[i]&1){
        cout<<"IMPOSSIBLE\n";
            return;
        }
    }

    vector<bool>vis(m,0);
    vector<int>path;

    getpath(0,adj,path,vis);
    reverse(path.begin(), path.end());

    if((int)path.size() != M + 1){
    cout<<"IMPOSSIBLE\n";
    return;
}

    for (int x : path)
        cout << x+1<< " ";

    cout << "\n";
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