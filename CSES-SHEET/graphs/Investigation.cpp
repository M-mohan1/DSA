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
void Testcases()
{
    cin>>n>>m;
    vector<vector<pair<int,ll>>>adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        ll c;
        cin>>c;
        --u;
        --v;
        adj[u].push_back({v,c});
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
    vector<vector<ll>>dist(n,vector<ll>(4,LLONG_MAX));;
    dist[0][0]=0;
    dist[0][1]=1;
    dist[0][2]=0;
    dist[0][3]=0;

    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(d>dist[u][0]) continue;

        for(auto &it:adj[u]){

            int v=it.first;
            ll w=it.second;

            if(dist[v][0]>d+w){
                dist[v][0]=d+w;
                dist[v][1]=dist[u][1];
                dist[v][2]=dist[u][2]+1;
                dist[v][3]=dist[u][3]+1;

                pq.push({dist[v][0],v});
            }
            else if(dist[v][0]==(d+w)){
                dist[v][1]=(dist[u][1]+dist[v][1])%mod;
                dist[v][2]=min(dist[v][2],dist[u][2]+1);
                dist[v][3]=max(dist[v][3],dist[u][3]+1);
            }
        }
    }

    cout<<dist[n-1][0]<<" "<<dist[n-1][1]<<" "<<dist[n-1][2]<<" "<<dist[n-1][3]<<"\n";
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