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
vector<ll>seg;

ll query(int idx,int l,int r,int q1,int q2){
    if(l>=q1 && r<=q2) return seg[idx];

    if(l>q2 || r<q1) return 0;

    int mid=(l+r)/2;
    ll p1=query(2*idx+1,l,mid,q1,q2);
    ll p2=query(2*idx+2,mid+1,r,q1,q2);

    return (p1+p2)%mod;

}

void update(int idx,int l,int r,int pos,ll val){

    if(l==r) {
        seg[idx]=(seg[idx]+val)%mod;
        return;
    }
    int mid=(l+r)/2;
    if(pos>mid) update(2*idx+2,mid+1,r,pos,val);
    else update(2*idx+1,l,mid,pos,val);

    seg[idx]=(seg[2*idx+1]+seg[2*idx+2])%mod;

}

void solve()
{
    int n;
    cin>>n;
    iv(a,n);

    vector<int>allval(n);
    f(i,0,n) allval[i]=a[i];
    
    // coordinate compression
    sort(allval.begin(),allval.end());

    allval.erase(unique(allval.begin(),allval.end()),allval.end());
    
    auto getId=[&](int x){
        return (int)(lower_bound(allval.begin(),allval.end(),x)-allval.begin());
    };

    int max_id=allval.size();
    seg.assign(max_id*4,0);

    for(int i=0;i<n;i++){
        int val=a[i];
        int id=getId(val);
        ll cnt=(id>0)?(query(0,0,max_id-1,0,id-1)):0;
        cnt=(cnt+1)%mod;

        update(0,0,max_id-1,id,cnt);
    }

    ll ans=query(0,0,max_id-1,0,max_id-1)%mod;
    pans
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