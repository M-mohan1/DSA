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
    
    int n, m;
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

    vector<int>topo;
    queue<int>q;

    f(i,0,n) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();

        topo.push_back(u);

        for(auto &v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }

    vector<int>nextNode(n);
    vector<int>dp(n,-1);
    dp[n-1]=1;

    for(int i=(int)topo.size()-1;i>=0;i--){
        int u=topo[i];
        for(auto &v:adj[u]){

            if(dp[v]==-1) continue;

            if(dp[v]+1>dp[u]){
                dp[u]=dp[v]+1;
                nextNode[u]=v;
            }
        }
    }

    if(dp[0] == -1) {
    cout << "IMPOSSIBLE\n";
    return;
    }
    
    vector<int> path;

    int cur=0;

    while(cur!=n-1) {
    path.push_back(cur);
    cur=nextNode[cur];
    }


    path.push_back(n-1);

    cout<<path.size()<<"\n";
    for(auto x:path)  cout<<x+1<<" ";
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