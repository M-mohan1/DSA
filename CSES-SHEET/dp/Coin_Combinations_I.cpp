#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;
#define iv(v,n) vector<ll>v(n); f(i,0,n) cin>>v[i]
#define printcount cout<<count<<endl;
#define i_n int i=0;i<n;i++
#define f(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
bool prime(int n){ if(n==1) return false; for(int i=2;i*i<=n;i++) if(n%i==0) return false; return true; }
int binS(vector<int>&a,int t){ int s=0,e=a.size()-1; while(s<=e){ int m=(s+e)/2; if(t>a[m]) s=m+1; else if(t<a[m]) e=m-1; else return m;} return -1; }
int power(int a,int b){ int r=1; while(b>0){ if(b&1) r*=a; a*=a; b>>=1;} return r; }
const int MOD = 1e9+7;
int rec(vector<ll>& coins, ll x,vector<ll>&dp,ll curr,int n) {
    if(curr==x) return 1;
    if(curr>x) return 0;
    ll cnt=0;
    if(dp[curr]!=-1) return  dp[curr];
    for(int i=0;i<n;i++){
    cnt =(cnt+rec(coins,x,dp,curr+coins[i],n))%MOD;
    }
    return dp[curr]=cnt;
}
void solve()
{
    int n;
    int x;
    cin>>n>>x;
    iv(a,n);
    vector<ll>dp(x+1,-1);
    int ans=rec(a,x,dp,0,n);
    if(ans==1e9) cout<<"-1\n";
    else
    cout << ans << endl;
}
int main()
{
    fast_io;
    int tt=1;
    //cin >> tt;
    while(tt--)
    {
        solve();
    }
}


