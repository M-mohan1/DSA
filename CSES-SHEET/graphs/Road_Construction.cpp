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
                
vector<int>parent;
vector<int>Rank;
unordered_map<int,int>mp;
priority_queue<int>pq;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void Unite(int x,int y){
    int p1=find(x);
    int p2=find(y);

    if(p1==p2) return;

    if(Rank[p1]>Rank[p2]) {
        parent[p2]=p1;
        mp[p1]+=mp[p2];
        pq.push(mp[p1]);
        mp.erase(p2);
    }

    else if(Rank[p1]<Rank[p2]) {
        parent[p1]=p2;
        mp[p2]+=mp[p1];
        pq.push(mp[p2]);
        mp.erase(p1);
    }
    else{
        Rank[p1]++;
        parent[p2]=p1;
        mp[p1]+=mp[p2];
        pq.push(mp[p1]);
        mp.erase(p2);
    }
}

void Testcases()
{
    int n,m;
    cin>>n>>m;

    parent.assign(n,-1);
    Rank.assign(n,1);

    f(i,0,n) {
        parent[i]=i;
        mp[i]++;
    }

    while(m--){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        Unite(u,v);

        cout<<mp.size()<<" "<<pq.top()<<"\n";
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