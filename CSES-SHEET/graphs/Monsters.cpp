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
vector<vector<pair<int,int>>>parent;
vector<vector<char>>dir;
int n;
int m;

void bfs(int i,int j,vector<vector<char>>&edges){

    queue<pair<int,int>>q;
    q.push({i,j});

    edges[i][j]='#';

    while(!q.empty()){

        auto [u,v]=q.front();
        q.pop();

        for(int k=0;k<4;k++){
            int nx=u+dx[k];
            int ny=v+dy[k];
            char go=mv[k];

            if(nx>=0 && ny>=0 && nx<n && ny<m && edges[nx][ny]!='#'){
                if(edges[nx][ny]=='.') edges[nx][ny]='#';
                parent[nx][ny]={u,v};
            }

        }



    }
}
void Testcases()
{
    cin>>n>>m;

    vector<vector<char>>edges(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>edges[i][j];
        }
    }

    parent.assign(n,vector<pair<int,int>>(m,{-1,-1}));
    dir.assign(n,vector<char>(m,'\0'));

}
int main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        Testcases();
    }
}