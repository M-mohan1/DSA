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
                

class SegmentTree {
public:
int n;
vector<long long> seg;

SegmentTree(int sz) {
    n = sz;
    seg.assign(4 * sz, 0);
}

void update(int idx, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    
    int mid = (l + r) / 2;
    
    if (pos <= mid)
    update(2 * idx+1, l, mid, pos, val);
    else
    update(2 * idx+2, mid + 1, r, pos, val);
    
    seg[idx] = max(seg[2 * idx+1],seg[2 * idx+2]);
}

long long query(int idx, int l, int r, int ql, int qr) {
    if (r < ql || l > qr)
    return LLONG_MIN;   
    
    if (ql <= l && r <= qr)
    return seg[idx];
    
    int mid = (l + r) / 2;
    
    int p1=query(2 * idx+1, l, mid, ql, qr);
    int p2=query(2 * idx + 2, mid + 1, r, ql, qr);
    return max(p1,p2);
}

void set(int pos, long long val) {
    update(0, 0, n - 1, pos, val);
}

ll  rangeSum(int l, int r) {
    return query(0, 0, n - 1, l, r);
}
};

vector<vector<int>>adj;
vector<int> start;
vector<int> finish;
vector<ll> euler;
int timer = 0;

void euler_tour(int node, int parent,vector<int>&value) {
    start[node] = timer;
    euler[timer]=value[node];
    timer++;
    
    for (int nxt : adj[node]) {
        if (nxt != parent)
        euler_tour(nxt, node,value);
    }
    
    euler[timer]-=value[node];
    finish[node] = timer;
    timer++;
}


void Testcases()
{
    int n,q;
    cin>>n>>q;

    iv(value,n);

    adj.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    start.resize(n);
    finish.resize(n);
    euler.resize(2*n);

    euler_tour(0, -1,value);

    SegmentTree seg(2*n);

    for (int i = 0; i < 2*n; i++) {
        seg.set(i, euler[i]);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int node, val;
            cin >> node >> val;
            --node;

            euler[start[node]] = val;
            euler[finish[node]] = -val;

            seg.set(start[node], val);
            seg.set(finish[node], -val);
        }
        else {
            int u,v;
            cin >>u,v ;
            --u;
            --v;
            cout <<seg.rangeSum(start[u], start[v]-1)<< '\n';
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