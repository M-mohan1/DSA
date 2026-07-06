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
                
int ans ;
vector<vector<int>>adj;
ll base_node=0;
vector<ll>subTree;
int N;

int dfs(int u,int parent, int curr_depth){
    ll total_nodes=1;
    base_node+=curr_depth;

    for(auto &v:adj[u]){
        if(v==parent) continue;

        total_nodes+=dfs(v,u,curr_depth+1);
    }
    subTree[u]=total_nodes;
    return total_nodes;
}

void get_ans(int parent,int prev,vector<ll>&result){

    for(auto&v:adj[parent]){
        if(v==prev) continue;

        result[v]=result[parent] - subTree[v] + ( N-subTree[v]);
        get_ans(v,parent,result);
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

    subTree.resize(n);
    dfs(0,-1,0);

    vector<ll>result(n);
    result[0]=base_node;
    get_ans(0,-1,result);

    for(auto &x:result) cout<<x<<" ";
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