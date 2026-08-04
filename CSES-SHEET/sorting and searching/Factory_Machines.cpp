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
                

bool check(vector<int>&arr,ll mid,int  t){
    ll process=0;

    for(int i=0;i<arr.size();i++){
        process+=mid/arr[i];

        if(process>=t) return true ;
    }

    return process>=t;
}

void Testcases()
{
    int n,t;
    cin>>n>>t;

    iv(arr,n);

    ll l=1;
    ll r=*min_element(arr.begin(),arr.end())*1LL;
    r=r*t;


    while(l<r){
        ll mid= l+(r-l)/2;

        if(check(arr,mid,t)){
            r=mid;
        }
        else l=mid+1;
    }

    cout<<r<<"\n";
    
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