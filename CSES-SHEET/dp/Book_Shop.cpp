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
    int n,x;
    cin>>n>>x;
    iv(a,n);
    iv(b,n);
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    for(int i=n-1;i>=0;i--){ // idx
        for(int j=1;j<=x;j++){ // current spended money (j-a[idx]) = left money.
            int take=0;
            if(j-a[i]>=0) take=b[i]+dp[i+1][j-a[i]];
            int not_take=dp[i+1][j];
            dp[i][j]=max(take,not_take);
        }
    }

    cout<<dp[0][x]<<"\n";
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