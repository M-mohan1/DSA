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
int LOG=30;
vector<vector<int>>dp;

void filldp(vector<int>&parent){
    f(i,0,N){
        dp[i][0]=parent[i];
    }

    for(int j=1;j<LOG;j++){
        for(int node=0;node<N;node++){
            if(dp[node][j-1]!=-1){
                dp[node][j]=dp[dp[node][j-1]][j-1];
            }
        }
    }
}

int query(int u,int k){
    for(int j=0;j<LOG;j++){
        if(k &(1<<j)){
            u=dp[u][j];
        }
    }
    return u;
}

void Testcases()
{
    int n,q;
    cin>>n>>q;
    vector<int>parent(n);
    f(i,0,n){
        cin>>parent[i];
        parent[i]--;
    }

    N=n;
    // LOG=log2(n);
    dp.assign(n+1,vector<int>(LOG+1,-1));

    filldp(parent);

    while(q--){
        int u,k;
        cin>>u>>k;
        u--;
        cout<<query(u,k)+1<<"\n";
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