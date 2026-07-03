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

string dp[3001][3001];
string help(int i,int j,vector<vector<char>>&grid,int n){
    if(i==n-1 && j==n-1)
    return string(1,grid[i][j]);

        if(i>=n || j>=n) return "{";


        if(dp[i][j]!="") return dp[i][j];

        string take="";
        take.push_back(grid[i][j]);
        take+=help(i,j+1,grid,n);

        string not_take="";
        not_take.push_back(grid[i][j]);
        not_take+=help(i+1,j,grid,n);

        return dp[i][j]=min(take,not_take);
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<char>> grid(n, vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    // memset(dp,0,sizeof(dp));

    string ans=help(0,0,grid,n);
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