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
    
    vector<vector<pair<int,ll>>>adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        ll c;
        cin>>c;
        --u;
        --v;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
        vector<bool>vis(n,0);
        pq.push({0,0});

        ll cost=0;
        while(!pq.empty()){
            auto[d,u]=pq.top();
            pq.pop();

            if(vis[u]==true) continue;
            cost+=d;
            vis[u]=1;

            for(auto &it:adj[u]){
                int v=it.first;
                ll newD=it.second;
                if(!vis[v]){
                    pq.push({newD,v});
                }
            }
        }

        if(vis[n-1]==false) {
            cout<<"IMPOSSIBLE\n";
            return;
        }
        cout<<cost<<"\n";
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