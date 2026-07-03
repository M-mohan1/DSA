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

    vector<vector<int>>edges;
    vector<vector<int>>adj(n);

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back({u-1,v-1,w});
        adj[u-1].push_back(v-1);
    }

    vector<ll>dist(n,LLONG_MIN);
    vector<bool>crime(n,0);  // saree criminal 

    dist[0]=0;

    for(int c=1;c<=n-1;c++){
        for(auto &it:edges){

                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(dist[u] != LLONG_MIN && dist[u] + w > dist[v]) {
                    dist[v] = dist[u] + w;
                }            
            }
        }

        for(auto it:edges){

                int u=it[0];
                int v=it[1];
                int w=it[2];

                if(dist[u]==LLONG_MIN) continue;
                if(dist[u]+w>dist[v]) {
                    crime[v]=1;
                }
            }

            queue<int>q;
            f(i,0,n) {
                if(crime[i]==1) q.push(i);
            }
            
            // criminals ke bhai bandu 
            while(!q.empty()){
                int u=q.front();
                q.pop();

                for(int v : adj[u]) {
                    if (!crime[v]) {
                    crime[v] = 1;
                    q.push(v);
                    }
                }
            }

            if(crime[n-1]) cout<<"-1\n";  // criminal hai 
            else cout<<dist[n-1]<<"\n";

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