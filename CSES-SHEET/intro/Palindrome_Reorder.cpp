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
    string s;
    cin>>s;

    int n=s.length();

    vector<int> cnt(26, 0);

    for (char ch : s)
        cnt[ch - 'A']++;


    int odd = 0;
    char mid = '#';

    for (int i = 0; i < 26; i++) {

        if (cnt[i] % 2) {
            odd++;
            mid = 'A' + i;
        }
    }

    if (odd > 1)
        {
            cout<<"NO SOLUTION";
            return ;
        }


    string half = "";
    for (int i = 0; i < 26; i++){
        int len=cnt[i]/2;

        while(len--){
            half.push_back('A'+i);
        }
    }

    string rev= half;
    reverse(rev.begin(),rev.end());

    if(odd==1) half.push_back(mid);

    half+=rev;

    cout<<half<<"\n";
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