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
const int mod=1e9+7 ;

int dp[19][10];
int help(int idx,string s,bool tight,int prev,bool lz){
    if(idx==(int)s.size()) return 1;

    if( tight==0 && !lz && prev>=0 &&  dp[idx][prev]!=-1) return dp[idx][prev];

    int curr=0;
    int lb=0;
    int ub= tight?s[idx]-'0':9;

    for(int k=lb;k<=ub;k++){
        bool newlz=(lz && k==0)? 1:0 ;

        if(!newlz && k==prev) continue;
        int newprev= newlz ? -1:k;
        curr+=help(idx+1,s,tight && k==ub,newprev,newlz);
    }

    if( tight==0 && !lz && prev>=0) dp[idx][prev]=curr;

    return curr;
}
int func(int n){

    if(n<0) return 0;

    string s=to_string(n);

    memset(dp,-1,sizeof(dp));

    return help(0,s,1,-1,1);
}
void solve()
{
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;


    int ans=func(n2)-func(n1-1);
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