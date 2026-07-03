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

vector<ll>dp;

ll help(int idx,vector<vector<int>>&vec,vector<int>&start){
    if(idx==(int)start.size()) return 0;

    if(dp[idx]!=-1) return dp[idx];

    int new_idx=upper_bound(start.begin(),start.end(),vec[idx][1])-start.begin();

    ll take=vec[idx][2]+help(new_idx,vec,start);
    ll not_take=help(idx+1,vec,start);

    return dp[idx]=max(take,not_take);
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>vec;
    vector<int>start;

    f(i,0,n){
        int st,end,profit;
        cin>>st>>end>>profit;

        vec.push_back({st,end,profit});
        start.push_back(st);
        
    }

    sort(vec.begin(),vec.end());
    sort(start.begin(),start.end());

    dp.assign(n+1,-1);

    ll ans=help(0,vec,start);
    cout<<ans<<"\n";
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