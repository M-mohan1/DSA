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
vector<ll>dist;


void  dfs(int u,int parent,int d){

    dist[u]=d;
    for(auto &v:adj[u]){
        if(v==parent) continue;
        dfs(v,u,d+1);
    }
}

void Testcases()
{
    int n;
    cin>>n;

    N=n;

    adj.resize(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dist.assign(n,0);
    dfs(0,-1,0);

    int end1=-1;
    ll maxi=-1;

    f(i,0,n){
        if(dist[i]>maxi){
            maxi=dist[i];
            end1=i;
        }
    }

    dist.assign(n,0);
    dfs(end1,-1,0);
    vector<ll>dist_end1=dist;

    int end2=-1;
    maxi=-1;

    f(i,0,n){
        if(dist[i]>maxi){
            maxi=dist[i];
            end2=i;
        }
    }

    dist.assign(n,0);
    dfs(end2,-1,0);
    vector<ll>dist_end2=dist;

    for(int i=0;i<n;i++) {
        cout<<max(dist_end1[i],dist_end2[i])<<" ";
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