

// this time we have to create a vector of  segment trees  for all length till k+1;
// build segment tree with values over sums ;

#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);

#define ll long long

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                

class SegTree{
public:
    int n;
    vector<ll>tree;

    SegTree(int n){
        this->n=n;
        tree.assign(4*n,0LL);
    }

    void update(int idx,int l,int r,int pos,ll val){
        if(l==r){
            tree[idx]+=val;
            return ;
        }

        int mid=(l+r)/2;

        if(pos<=mid){
            update(2*idx+1,l,mid,pos,val);
        }
        else update(2*idx+2,mid+1,r,pos,val);

        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void update(int pos, ll val) {
        update(0, 0, n - 1, pos, val);
    }


    ll query(int idx,int l,int r,int q1,int q2){

        if(r<q1 || l>q2) return 0LL;
        if (q1 <= l && r <= q2) return tree[idx];

        int mid=(l+r)/2;
        ll p1=query(2*idx+1,l,mid,q1,q2);
        ll p2=query(2*idx+2,mid+1,r,q1,q2);

        return p1+p2;
    }

    ll query(int q1, int q2) {
        q1 = max(0, q1); 
        
        if (q1 > q2) return 0LL;
        return query(0, 0, n - 1, q1, min(q2, n - 1));
    }
};


void Testcases()
{
    int n,k;
    cin>>n>>k;
    k++; 

    iv(arr,n);

    int mx = *max_element(arr.begin(), arr.end());

    vector<SegTree> st(k + 1, SegTree(mx + 1));

    for (int i = 0; i < n; i++) {
        st[1].update(arr[i], 1);

        for (int len = 2; len <= k; len++) {
            ll past_sequences = st[len - 1].query(1, arr[i] - 1);
            
            if (past_sequences > 0) {
                st[len].update(arr[i], past_sequences);
            }
        }
    }

    cout << st[k].query(1, mx) << "\n";
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