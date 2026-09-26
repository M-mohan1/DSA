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

    if(n==1){
        cout<<"1\n";
        return ;
    }

    if(n<=3) {
        cout<<"NO SOLUTION\n";
        return ;
    }

    if(n==4){
        cout<<"3 "<<"1 "<<"4 "<<"2"<<"\n";
    }
    
    else{
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }

        cout<<"\n";
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