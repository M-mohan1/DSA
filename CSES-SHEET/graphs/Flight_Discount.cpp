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

    vector<vector<pair<int,int>>>adj(n);

    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        --u;
        --v;
        adj[u].push_back({v,c});
    }

    vector<vector<ll>>dist(n,vector<ll>(2,LLONG_MAX));   // state 0= not take coupen yet , state 1 = coupen is used 

    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>>pq;  // store state too

    pq.push({0,0,0});
    dist[0][0]=0;

    while(!pq.empty()){

        auto [curr_dist,u,state]=pq.top();
        pq.pop();

        if(curr_dist > dist[u][state]) continue;

        for(auto &nbr:adj[u]){

            int v=nbr.first;
            int nw=nbr.second;

            if(state==0){
                if(dist[v][0]>curr_dist+nw){
                dist[v][0]=curr_dist+nw;
                pq.push({dist[v][0],v,0});
            }
                if(dist[v][1]>curr_dist+nw/2){
                dist[v][1]=curr_dist+nw/2;
                pq.push({dist[v][1],v,1});
            }
        }
        else{
            if(dist[v][1]>curr_dist+nw){
                dist[v][1]=curr_dist+nw;
                pq.push({dist[v][1],v,1});
            }
        }
    }
}
    cout<<dist[n-1][1]<<"\n"; // 1  beacuse we have to use that one coupen 
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