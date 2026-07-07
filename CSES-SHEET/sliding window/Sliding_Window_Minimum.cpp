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
                
void Testcases()
{
    int n,k;
    cin>>n>>k;

    int x,a,b,c;
    cin>>x>>a>>b>>c;

    vector<ll>arr(n);
    arr[0]=x;
    f(i,1,n){
        arr[i]=(arr[i-1]*a+b)%c;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

    f(i,0,k)
        pq.push({arr[i], i});

    ll ans = 0;
    ans ^= pq.top().first;

    int j = 1; 

    for(int i = k; i < n; i++, j++)
    {
        pq.push({arr[i], i});
        while(!pq.empty() && pq.top().second < j)
            pq.pop();

        ans ^= pq.top().first;
    }

    cout << ans << "\n";
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