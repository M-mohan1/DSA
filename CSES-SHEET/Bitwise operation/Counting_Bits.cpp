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
    ll n;
    cin>>n;

    ll ans=0;
    vector<int>arr(8);
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    arr[3]=1;
    arr[4]=2;
    arr[5]=2;
    arr[6]=3;
    arr[7]=1;

    vector<ll>pref(8);
    pref[0]=arr[0];
    f(i,1,8){
        pref[i]=pref[i-1]+arr[i];
    }

    if(n<=8) {
        cout<<pref[n-1];
        return ;
    }

    ll val=n/8LL;
    ll rem=n%8;

    ans+=(1LL*val*pref[7]);
    ans+=8*(val-1);
    if(rem!=0 ) ans+=1LL*pref[rem-1]+rem;

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