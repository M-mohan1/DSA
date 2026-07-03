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
                
struct Edge{
    int to;
    ll cap;
    int rev;
};

class Dinic{
    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;

public:
    Dinic(int n){
        this->n = n;
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void addEdge(int u,int v,int cap){
        Edge a = {v, cap, (int)g[v].size()};
        Edge b = {u, 0,   (int)g[u].size()};

        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs(int s,int t){
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(s);
        level[s]=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &e:g[u]){
                if(level[e.to]==-1 && e.cap>0){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
            }
        }

        return level[t]!=-1;
    }

    int dfs(int u,int t,ll flow){
        if(u==t || flow==0) return flow;

        for(int &i=ptr[u]; i<g[u].size(); i++){
            Edge &e=g[u][i];

            if(level[e.to]!=level[u]+1 || e.cap==0)
                continue;

            int pushed=dfs(e.to,t,min(flow,e.cap));

            if(pushed){
                e.cap-=pushed;
                g[e.to][e.rev].cap+=pushed;
                return pushed;
            }
        }

        return 0;
    }

    ll maxflow(int s,int t){
        ll flow=0;

        while(bfs(s,t)){
            fill(ptr.begin(), ptr.end(), 0);

            while(int pushed=dfs(s,t,1e18))
                flow+=pushed;
        }

        return flow;
    }
};

void Testcases()
{
    int n,m;
    cin>>n>>m;

    Dinic d(n+1);

    while(m--){
        int u,v,cap;
        cin>>u>>v>>cap;

        d.addEdge(u,v,cap);
    }

    ll ans=d.maxflow(1,n);
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