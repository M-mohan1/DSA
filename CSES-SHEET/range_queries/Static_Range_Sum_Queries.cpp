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


void build(int i,int l,int r,vector<int>&a,vector<ll>&seg){
    if(l==r){
        seg[i]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*i+1,l,mid,a,seg);
    build(2*i+2,mid+1,r,a,seg);
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
ll query(int i,int l,int r,int a,int b,vector<ll>&seg){
if(l>b || r<a) return 0;
if(l>=a && r<=b) return seg[i];
int mid=(l+r)/2;
ll p1=query(2*i+1,l,mid,a,b,seg);
ll p2=query(2*i+2,mid+1,r,a,b,seg);
return p1+p2;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    iv(a,n);
    vector<ll>seg(4*n,0);
    build(0,0,n-1,a,seg);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<query(0,0,n-1,a-1,b-1,seg)<<"\n";
    }
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