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


vector<int>pi_array(string & p){
int n=p.size();
vector<int>ans(n,0);
for(int i=1;i<n;i++){
    int j=ans[i-1];
    while(j>0 && p[i]!=p[j]) j=ans[j-1];
    if(p[i]==p[j]) j++;
    ans[i]=j;
}
return ans;
}
void solve()
{
    string s;
    cin>>s;
    string pat;
    cin>>pat;
    int n=s.size();
    int m=pat.size();
    vector<int>pi=pi_array(pat);
    int cnt =0;
    int i=0;
    int j=0;
    while(i<n){
        if(s[i]==pat[j]){
            i++;
            j++;
        }
        if(j==m){
            cnt++;
            j=pi[j-1];
        }
        else if(i<n && s[i]!=pat[j]){
            if(j!=0) j=pi[j-1];
            else i++;
        }
    }

    cout<<cnt<<"\n";
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