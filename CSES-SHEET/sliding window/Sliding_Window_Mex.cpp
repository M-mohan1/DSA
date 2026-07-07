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
    set<int>st;
    f(i,0,k+1) st.insert(i);

    int j=0;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==1) st.erase(arr[i]);
        
        if(i-j+1<k) continue;
        else{
            cout<<*begin(st)<<" ";

            if(mp[arr[j]]==1) {
                mp.erase(arr[j]);
                st.insert(arr[j]);
            }
            else{
                mp[arr[j]]--;
            }
            j++;
        }
    }
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