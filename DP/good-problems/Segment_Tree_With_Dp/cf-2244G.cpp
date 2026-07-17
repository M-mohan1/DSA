// dp +Memo gives TLE and MLE 
// use segment / BIT for get max from previous with 1D DP and activate array .
// Tricky to think 


//Rule A: i - j > arr[i] == j < i - arr[i]  
//Rule B: i - j > arr[j] == i > j + arr[j]

//Next time you hit a TLE on a 1D DP problem:

//Isolate the i terms from the j terms in your if conditions.
//If one condition looks like a range bound (j < limit), grab a Segment Tree.
//If another condition looks like a time delay (i > unlock_time), grab a scheduling array.



#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long


#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                
struct SegTree {
    int n;
    vector<ll> tree;
    
    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n, 0LL);
    }
    
    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    void update(int idx, ll val) {
        update(1, 0, n - 1, idx, val);
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0LL; 
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        ll left_max = query(2 * node, start, mid, l, r);
        ll right_max = query(2 * node + 1, mid + 1, end, l, r);
        return max(left_max, right_max);
    }
    
    ll query(int l, int r) {
        if (l > r || l < 0) return 0LL;
        return query(1, 0, n - 1, l, min(r, n - 1));
    }
};

void Testcases()
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    f(i, 0, n) cin >> arr[i];

    vector<ll> dp(n, 0);
    
    vector<vector<int>> activate(n);
    
    SegTree st(n);
    ll ans = 0;

    f(i, 0, n) {

        for (int j : activate[i]) {
            st.update(j, dp[j]);
        }

        int limit = i - arr[i] - 1;
        ll max_prev = 0;
        if (limit >= 0) {
            max_prev = st.query(0, limit); 
        }
        

        dp[i] = arr[i] + max_prev;
        ans = max(ans, dp[i]);

        ll active_time = i + arr[i] + 1;
        if (active_time < n) {
            activate[active_time].push_back(i);
        }
    }

    cout << ans << "\n";
}
int main()
{
    fast_io;
    int tt=1;
    cin >> tt;
    while(tt--)
    {
        Testcases();
    }
}