/*
If someone has achieved it before, it means it's possible.
Every accepted solution was once a wrong answer.
The expert in anything was once a beginner.
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define rev(v) reverse(all(v))

#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                
ll ans = LLONG_MAX;
ll total = 0;

void solve(int i, long long sum,vector<int>&a) {
    if (i == a.size()) {
        ans = min(ans, abs(total - 2 * sum));
        return;
    }

    solve(i + 1, sum,a);           
    solve(i + 1, sum + a[i],a);  
}

void Testcases()
{
    int n;
    cin>>n;

    iv(arr,n);

    total=accumulate(arr.begin(),arr.end(),0LL);

    solve(0,0,arr);
    cout<<ans<<"\n";


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