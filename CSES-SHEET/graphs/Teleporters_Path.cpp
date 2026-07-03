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
                

void getpath(int u,
        unordered_map<int,vector<int>>& adj,
        vector<int>& path){


    while(!adj[u].empty()){

        int v = adj[u].back();
        adj[u].pop_back();

        getpath(v, adj, path);
    }

    path.push_back(u);
}

void Testcases()
{
    int n,m;
    cin>>n>>m;
    int M=m;
    unordered_map<int,vector<int>>adj;
    vector<int>in(n,0);
    vector<int>od(n,0);

    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        adj[u].push_back(v);
        in[v]++;
        od[u]++;
    }

    if(od[0] != in[0] + 1) {
        cout<<"IMPOSSIBLE\n";
        return;
    }

    if(in[n-1] != od[n-1] + 1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for(int i=1;i<n-1;i++){
    if(in[i] != od[i]) {
        cout<<"IMPOSSIBLE\n";
        return;
    }
}

    vector<int>path;


    getpath(0,adj,path);

    reverse(path.begin(), path.end());

    if(path.size() != M+ 1){
    cout<<"IMPOSSIBLE\n";
    return;
    }
    
    if(path.front()!=0 || path.back()!=n-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    for (int x : path)
        cout << x+1<< " ";

    cout << "\n";
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