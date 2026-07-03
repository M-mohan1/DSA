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
    int n, m;
    cin>>n>>m;

    int q;
    cin>>q;
    vector<vector<ll>>dist(n,vector<ll>(n,LLONG_MAX));

    f(i,0,n) dist[i][i]=0;

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;

        dist[u-1][v-1]=min((ll)w,dist[u-1][v-1]);
        dist[v-1][u-1]=min((ll)w,dist[v-1][u-1]);  // many roads possible here with different weights
    }

    for(int via=0;via<n;via++){
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(dist[u][via]!=LLONG_MAX && dist[via][v]!=LLONG_MAX){
                    dist[u][v]=min(dist[u][v],dist[u][via]+dist[via][v]);
                }
            }
        }
    }

    while(q--){
        int u,v;
        cin>>u>>v;

        if(dist[u-1][v-1]!=LLONG_MAX) cout<<dist[u-1][v-1]<<"\n";
        else cout<<-1<<"\n";
    }

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