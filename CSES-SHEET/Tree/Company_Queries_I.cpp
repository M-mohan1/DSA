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
                
int N;
vector<int>parent;
vector<vector<int>>dp;
int LOG;

void TreeAncester(){

    for(int root=0;root<N;root++){
        dp[root][0]=parent[root];
    }

    for(int j=1;j<LOG;j++){
        for(int v=0;v<=N;v++){
            if(dp[v][j-1]!=-1){
                dp[v][j]=dp[dp[v][j-1]][j-1];
            }
        }
    }
}

int getAncester(int u,int k){
    LOG=log2(N)+1;

    for(int j=0;j<LOG;j++){
        if(k & (1<<j)){
            u=dp[u][j];
            if(u==-1) return -1;
        }
    }

    return u+1;
}

void Testcases()
{
    int n,q;
    cin>>n>>q;

    parent.assign(n,-1);
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        --x;
        parent[i]=x;
    }

    N=n;
    LOG=log2(n)+1;
    dp.assign(n+1,vector<int>(LOG,-1));

    TreeAncester();

    while(q--){
        int u,k;
        cin>>u>>k;
        --u;
        cout<<getAncester(u,k)<<"\n";
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