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

int help(int i,int k,int curr,int n,vector<vector<int>>&dp){
    if(curr==k) return 1;
    if(i>=n || curr>k) return 0;

    if(dp[i][curr]!=-1) return dp[i][curr];

    ll not_take=help(i+1,k,curr,n,dp)%mod;
    ll take=0;
    if(curr+i<=k) take=help(i+1,k,curr+i,n,dp)%mod;
    
    return  dp[i][curr]=(int)(take+not_take)%mod;

}
void solve()
{
    int n;
    cin>>n;

    ll sum=n*(n+1)/2;
    if(sum%2==1) {
        cout<<"0\n";
        return;
    }

    vector<vector<int>>dp(n+2,vector<int>(sum/2+1,-1));

    ll ways = help(1,sum/2,0,n,dp);
    //ll ans = ways * 500000004LL % mod;
    //pans
    cout<<ways<<"\n";
}
int main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        solve();
    }
}