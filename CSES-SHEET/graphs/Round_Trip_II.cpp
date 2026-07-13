#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;
#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define printcount cout<<count<<endl;
#define i_n int i=0;i<n;i++
#define f(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
bool prime(int n){ if(n==1) return false; for(int i=2;i*i<=n;i++) if(n%i==0) return false; return true; }
int binS(vector<int>&a,int t){ int s=0,e=a.size()-1; while(s<=e){ int m=(s+e)/2; if(t>a[m]) s=m+1; else if(t<a[m]) e=m-1; else return m;} return -1; }
int power(int a,int b){ int r=1; while(b>0){ if(b&1) r*=a; a*=a; b>>=1;} return r; }
const int mod=1e9+7 ;
                
int n;
vector<vector<int>>adj;
vector<int>parent;
vector<int>vis;
int cycle_start;
int cycle_end;

bool dfs(int u) {
    vis[u] = 1; 

    for (auto &v : adj[u]) {
        if (vis[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } 
        else if (vis[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    
    }
    
    vis[u] = 2; 
    return false;
}

void Testcases()
{
    int m;
    cin>>n>>m;

    adj.resize(n);
    parent.assign(n,-1);
    vis.assign(n,0);

    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
    }
    
    cycle_end=-1;
    cycle_start=-1;

    
    for(int i=0;i<n;i++){
        if(!vis[i] && dfs(i)) break;
    }

    if(cycle_start==-1) {
        cout<<"IMPOSSIBLE\n";
        return;
    }

    vector<int>cycle;
    int curr=cycle_end;
    cycle.push_back(cycle_start);

    while(curr!=cycle_start){
        cycle.push_back(curr);
        curr=parent[curr];
    }

    cycle.push_back(cycle_start);

        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<"\n";
        for(auto &it:cycle) cout<<it+1<<" ";
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