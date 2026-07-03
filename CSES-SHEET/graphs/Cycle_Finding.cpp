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
    
    vector<vector<int>>edges;
    vector<int>parent(n,-1);
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        --u;
        --v;
        edges.push_back({u,v,c});
    }

    vector<ll>dist(n,0);
    int crime=-1;

    for(int i=0;i<=n-1;i++){
        crime=-1;

        for(auto &it:edges){
            int u=it[0] ;
            int v=it[1];
            int c=it[2];

            if( dist[u]+c<dist[v]){
                dist[v]=dist[u]+c;
                parent[v]=u;
                crime=v;
            }
        }
    }


        if(crime==-1) {
            cout<<"NO\n";
            return;
        }

        for(int i=0;i<n;i++) crime=parent[crime];  // importanrt step we always end up with node inside cycle

        vector<int>cycle;

        int temp=crime;

        while(true){
            cycle.push_back(temp);
            if(temp==crime && cycle.size()>1) break;  // reach at start criminal again cycle complete
            temp=parent[temp];
        }

        rev(cycle);
        cout<<"YES\n";
        for(auto it:cycle) cout<<it+1<<" ";
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