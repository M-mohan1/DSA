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

    int k=n;
    vector<int>start;
    vector<int>end;

    while(k--){
        int x,y;
        cin>>x>>y;

        start.push_back(x);
        end.push_back(y);
    }

    sort(start.begin(),start.end());
    sort(end.begin(),end.end());

    int i=0;
    int j=0;
    int ans=0;
    int curr=0;
    
    while(i<n && j<n){
        if(start[i]<=end[j]){
            curr++;
            i++;
        }
        else{
            curr--;
            j++;
        }
        
        ans=max(ans,curr);
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