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
                
void Testcases()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int>parent(n,-1);
    vector<bool>vis(n,0);

    queue<int>q;
    q.push(0);
    vis[0]=1;
    parent[0]=-1;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        if(u==n-1){
            break ;
        }

        for(int &it:adj[u]){
            if(!vis[it]){
                parent[it]=u;
                vis[it]=1;
                q.push(it);
            }
        }
    }

    if(!vis[n-1]) cout<<"IMPOSSIBLE\n";
    else{
        vector<int>path;
        int curr=n-1;
        path.push_back(curr);

        while(parent[curr]!=-1){
            path.push_back(parent[curr]);
            curr=parent[curr];
        }

        reverse(path.begin(),path.end());
        cout<<path.size()<<"\n";
        f(i,0,path.size()) cout<<path[i]+1<<" ";
        cout<<"\n";
    }

}
int main()
{
    fast_io;
    int tt=1;
    //cin >> tt;
    while(tt--)
    {
        Testcases();
    }
}