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
                

struct compare {
    bool operator()(const pair<int,int>& p1, const pair<int,int>& p2) const {
        if (p1.first == p2.first) {    
            return p1.second < p2.second; 
        }
        return p1.first > p2.first;
    }
};

void Testcases()
{
    int n,k;
    cin>>n>>k;
    iv(arr,n);

    map<int,int>freq;
    set<pair<int,int>,compare>st;

    for(int i=0;i<k;i++){
        if(freq[arr[i]]>0){
            st.erase({freq[arr[i]],arr[i]});
        }

        freq[arr[i]]++;
        st.insert({freq[arr[i]],arr[i]});
    }

    cout << st.begin()->second << " ";

    for(int i=k;i<n;i++){
        int out_val = arr[i - k];
        int in_val = arr[i];   

        st.erase({freq[out_val], out_val});
        freq[out_val]--;
        if (freq[out_val] > 0) {
            st.insert({freq[out_val], out_val});
        }

        if (freq[in_val] > 0) {
            st.erase({freq[in_val], in_val});
        }
        freq[in_val]++;
        st.insert({freq[in_val], in_val});

        cout << st.begin()->second << " ";
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