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
const int mod=1e9+7;

vector<int>parent;
vector<int>Rank;

int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}

void Unite(int x,int y){
    int p1=find(x);
    int p2=find(y);

    if(p1==p2) return ;
    if(Rank[p1]>Rank[p2]) parent[p2]=p1;
    else if(Rank[p1]<Rank[p2]) parent[p1]=p2;
    else{
        parent[p1]=p2;
        Rank[p2]++;
    }
}

void Testcases()
{
    int n,m;
    cin>>n>>m;

    parent.assign(n,-1);
    Rank.assign(n,1);

    f(i,0,n) parent[i]=i;

    while(m--){
        int u;
        int v;
        cin>>u>>v;
        if(find(u-1)!=find(v-1)) Unite(u-1,v-1);
    }


    set<int>st;

    f(i,0,n){
        st.insert(find(i));
    }

    cout<<(int)st.size()-1<<"\n";
    vector<int> comp(st.begin(), st.end());

    for(int i=1;i<comp.size();i++){
    cout << comp[0]+1 << " " << comp[i]+1 << "\n";
}
}
int main()
{
    fast_io;
    int tt=1;
    //cin >> tt;
    while(tt--)
    {
        Testcases();
    }
}