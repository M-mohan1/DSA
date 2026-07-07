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

    vector<ll>prefix(n);
    prefix[0]=arr[0];

    f(i,1,n){
        prefix[i]=prefix[i-1]^arr[i];
    }

    ll ans =0;
    int j=k-1;
    int i=0;
    while(j<n){
        if(j==k-1) ans=ans^prefix[j];
        else {
            ans=ans^(prefix[j]^prefix[i]);
            i++;
        }
        j++;
    }

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