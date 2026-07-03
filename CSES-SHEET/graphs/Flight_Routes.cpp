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
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<pair<int,ll>>>adj(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        ll w;
        cin>>w;
        --u;
        --v;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
    vector<vector<ll>>dist(n);  //  get top k dist ,  not onlu one this time 

    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u]=pq.top();
        pq.pop();

        if(dist[u].size()>=k) continue;
        dist[u].push_back(d);

        for(auto &it:adj[u]){
            ll newDist=d+it.second;         // no relaxation we need more than one distances 
            pq.push({newDist,it.first});
        }
    }

    for(int i=0;i<k;i++){
        cout<<dist[n-1][i]<<" ";
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