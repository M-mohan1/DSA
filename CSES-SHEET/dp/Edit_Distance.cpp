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

void solve()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
    }
}
cout<<dp[n][m]<<"\n";
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