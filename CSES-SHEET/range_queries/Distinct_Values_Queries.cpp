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
                
struct fenwick {

    int n;
    vector<ll>bit;

    fenwick(int n){
        this->n=n;
        bit.assign(n+1,0);
    }

    void update(int idx, ll val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx & (-idx));
        }
    }

    ll query(int idx){
        ll sum =0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx & (-idx));
        }

        return sum ;
    }

    ll rangeQuery(int l,int r){
        return query(r)-query(l-1);
    }
};

struct Query{
    int id,l,r;
};

void Testcases()
{
    int n,q;
    cin>>n>>q;

    iv(a,n);

    vector<int> temp = a;
    srt(temp);
    temp.erase(unique(all(temp)), temp.end());
    
    f(i, 0, n) {
        a[i] = lower_bound(all(temp), a[i]) - temp.begin() + 1;
    }

    vector<Query> queries(q);

    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].id = i;
    }

    sort(queries.begin(), queries.end(),
        [](const Query &x, const Query &y) {
            return x.r < y.r;
        });

    fenwick ft(n);

    vector<int> last(n + 1, 0);
    vector<int> ans(q);

    int current = 0;

    for(auto query : queries) {

        while(current < query.r) {

            current++;

            int value = a[current-1];

            if(last[value] != 0) {
                ft.update(last[value], -1);
            }

            ft.update(current, +1);
            last[value] = current;
        }

        ans[query.id] = ft.rangeQuery(query.l, query.r);
    }

    for(int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
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