#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define int long long
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
int rec(vector<int>&arr,int n,int idx ,int curr,int k){
    if(idx==n){
        return curr==k;
    }
    int not_take=rec(arr,n,idx+1,curr,k);
    int take=0;
    if(arr[idx]<=k) take=rec(arr,n,idx+1,curr+arr[idx],k);
    return take+not_take;
}
void solve()
{
    const int MOD = 1e9 + 7;
    int n;
    cin>>n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }
    cout<<dp[n];
}

int32_t main()
{
    fast_io;
    int t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
}