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
                
int n,m;
void dfs(int u,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    //if(vis[u]==true) return ;
    vis[u]=1;
    for(auto &v:adj[u]){
        if(vis[v]==0) dfs(v,adj,vis,st);
    }
    st.push(u);
}

void dfs1(int u,vector<vector<int>>&adj,vector<int>&vis,int cnt){
    //if(vis[u]!=0) return ;
    vis[u]=cnt;
    for(auto &v:adj[u]){
        if(vis[v]==0) dfs1(v,adj,vis,cnt);
    }
}

void Testcases()
{
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

    vector<int>vis(n,0);
    stack<int>st;

    for(int i=0;i<n;i++){
        if(vis[i]==0) dfs(i,adj,vis,st);
            }

    f(i,0,n) vis[i]=0;

    int cnt=0;
    while(!st.empty()){

    int u=st.top();
    st.pop();
    
        if(vis[u]==0){
            ++cnt;

            dfs1(u,rev_adj,vis,cnt);
        }
    }

    cout<<cnt<<"\n";
    f(i,0,n) cout<<vis[i]<<" ";
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