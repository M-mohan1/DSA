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
    int n;
    cin>>n;

    ll w;
    cin>>w;

    iv(arr,n);

    vector<pair<int ,ll>>dp(1<<n,{n+1,0});

    dp[0]={1,0};

    for(int mask =1;mask<(1<<n);mask++){
        for(int i=0;i<n;i++){
            if(mask & ( 1<<i)){
                auto prev=dp[mask^(1<<i)];

                ll curr_w=prev.second;
                int rides=prev.first;
                pair<int,ll>options;
                if(curr_w + arr[i] <=w){
                    options={rides,curr_w+arr[i]};
                }
                else options ={rides+1,arr[i]};
                dp[mask]=min(dp[mask],options);
            }
        }
    }

    cout<<dp[(1<<n)-1].first<<"\n";
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