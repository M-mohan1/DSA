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

    deque<pair<int,int>>q;

    ll ans = 0;
    int j=0;
    for(int i=0;i<n;i++){
        while(!q.empty() && q.back().first>arr[i]) q.pop_back();
        q.push_back({arr[i],i});

        if(i-j+1<k) continue;
        else{
            ans=ans^q.front().first;
            if(q.front().second==j) q.pop_front();
            j++;
        }
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