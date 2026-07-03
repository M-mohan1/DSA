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
    int n;
    cin>>n;
    vector<pair<int,int>>h;

    f(i,0,n){
        int x;
        cin>>x;
        h.push_back({x,i});
    }

    vector<int>pge(n);
    vector<int>nge(n);

    stack<int>st;

    for(int i=0;i<n;i++){
        while(!st.empty() && h[i].first>=h[st.top()].first) st.pop();
        if(st.empty()) pge[i]=-1;
        else pge[i]=st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();


    for(int i=n-1;i>=0;i--){
        while(!st.empty() && h[i].first>=h[st.top()].first) st.pop();
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        st.push(i);
    }

    //sort(h.rbegin(),h.rend());
    vector<int>dp(n);

    for(int i=0;i<n;i++){
        int idx=h[i].second;

        int left=pge[idx];
        int right=nge[idx];

        dp[idx]=1;
        if(left!=-1) dp[idx]=max(dp[idx],dp[left]+1);
        if(right!=-1) dp[idx]=max(dp[idx],dp[right]+1);
    }

    int ans=*max_element(dp.begin(),dp.end());
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