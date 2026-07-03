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

    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    
    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int>q;
    f(i,0,n) {
        if(indegree[i]==0) q.push(i);
    }

    vector<int>topo;

    while(!q.empty()){

        int u=q.front();
        q.pop();
        topo.push_back(u);

        for(auto &v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }

    if(topo.size()!=n){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    f(i,0,n) cout<<topo[i]+1<<" ";
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