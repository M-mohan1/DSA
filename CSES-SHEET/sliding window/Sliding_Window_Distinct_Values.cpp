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
    iv(arr,n);

    map<int,int>mp;
    f(i,0,k)
        mp[arr[i]]++;

    vector<int>ans;
    ans.push_back(mp.size());
    int j = 1; 
    mp[arr[0]]--;
    if(mp[arr[0]]==0) mp.erase(arr[0]);

    int i=k;
    while(i<n){
        mp[arr[i]]++;
        ans.push_back(mp.size());
        mp[arr[j]]--;
        if(mp[arr[j]]==0) mp.erase(arr[j]);
        i++;
        j++;
    }

    for(auto &x:ans) cout<<x<<" ";
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