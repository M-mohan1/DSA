#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
//#define int long long
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


void solve()
{
    int n,sum;
    cin>>n>>sum;
    iv(a,n);

    vector<int> dp(sum+1,0);
    dp[0]=1;
    int ans=0;  

    for(int i=0;i<n;i++){
        for(int j=a[i];j<=sum;j++){
        dp[j] = (dp[j] + dp[j-a[i]]) % mod;
        }
    }
    ans=dp[sum];
    pans
}
int32_t main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        solve();
    }
}