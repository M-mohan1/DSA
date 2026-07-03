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

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int N,M;

void bfs(int i,int j,vector<vector<char>>&g){
if(i>=N || j>=M) return ;

queue<pair<int,int>>q;
q.push({i,j});
g[i][j]='#';

while(!q.empty()){

    auto it=q.front();
    q.pop();
    int u=it.first;
    int v=it.second;


    for(int k=0;k<4;k++){
        int nx=u+dx[k];
        int ny=v+dy[k];

        if(nx>=0 && nx<N && ny>=0 && ny<M && g[nx][ny]=='.'){
            g[nx][ny]='#';
            q.push({nx,ny});
        }
    }

}

}
void solve()
{
    int n,m;
    cin>>n>>m;
    N=n;
    M=m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<pair<int,int>>idx;
    f(i,0,n){
        f(j,0,m){
            cin>>grid[i][j];
            if(grid[i][j]=='.') idx.push_back({i,j});
        }
    }

    int cnt=0;
    for(auto &it:idx){
            if(grid[it.first][it.second]=='.')  {
                bfs(it.first,it.second,grid);
                cnt++;
            }
    }

    pcnt

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