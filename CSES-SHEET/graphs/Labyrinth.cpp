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
char mv[4]={'R','L','D','U'};

int N,M;

void solve()
{
    cin>>N>>M;

    vector<vector<char>> g(N,vector<char>(M));

    int sx=-1,sy=-1;
    int ex=-1,ey=-1;

    f(i,0,N){
        f(j,0,M){
            cin>>g[i][j];

            if(g[i][j]=='A'){
                sx=i;
                sy=j;
            }

            if(g[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }

    vector<vector<bool>> vis(N,vector<bool>(M,false));

    vector<vector<pair<int,int>>> par(
        N,vector<pair<int,int>>(M,{-1,-1})
    );

    vector<vector<char>> dir(
        N,vector<char>(M)
    );

    queue<pair<int,int>> q;

    q.push({sx,sy});
    vis[sx][sy]=true;

    while(!q.empty()){

        auto [u,v]=q.front();
        q.pop();

        for(int k=0;k<4;k++){

            int nx=u+dx[k];
            int ny=v+dy[k];

            if(nx>=0 && nx<N &&
                ny>=0 && ny<M &&
                !vis[nx][ny] &&
                g[nx][ny]!='#')
            {
                vis[nx][ny]=true;

                par[nx][ny]={u,v};
                dir[nx][ny]=mv[k];

                q.push({nx,ny});
            }
        }
    }

    if(!vis[ex][ey]){
        cout<<"NO\n";
        return;
    }

    string ans="";

    int x=ex;
    int y=ey;

    while(!(x==sx && y==sy)){

        ans.push_back(dir[x][y]);

        auto [px,py]=par[x][y];

        x=px;
        y=py;
    }

    reverse(ans.begin(),ans.end());

    cout<<"YES\n";
    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";
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