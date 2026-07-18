
/*
 * MODULO MEET IN THE MIDDLE - CORE LOGIC
 * Goal: Maximize (x + y) % m, where 0 <= x < m and 0 <= y < m.
 * Since x and y are < m, their sum is bounded: 0 <= x + y < 2m.
 * This creates exactly two ways to maximize the sum:
 * 
 * CASE 1: Keep sum strictly below 'm' (x + y < m) => y < m - x
 * - We want the largest y that is strictly less than (m - x).
 * - Code: auto it = lower_bound(all(right), m - x);
 * - Take *(it - 1) to get the largest valid y. 
 * - (Alternatively: upper_bound(all(right), m - 1 - x) and take *(it - 1))
 * 
 * CASE 2: Let sum overflow 'm' (x + y >= m) => wrap around to x + y - m
 * - To maximize this, we just want the absolute largest y possible.
 * - Code: Just take right.back()
 * 
 * Final Answer: Max( Case 1, Case 2 ) for every x in left.
 */


#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);
#define ll long long

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                
vector<ll>leftSums;
vector<ll>rightSums;
int m; 

void solve(int i,int end,vector<int>&arr,int curr){
    if(i==end){
        leftSums.push_back(curr);
        return ;
    }

        solve(i+1,end,arr,curr);
        solve(i+1,end,arr,(curr+arr[i])%m);
}

void solve1(int i,int end,vector<int>&arr,int curr){
    if(i==end){
        rightSums.push_back(curr);
        return ;
    }

        solve1(i+1,end,arr,curr);
        solve1(i+1,end,arr,(curr+arr[i])%m);
}

void Testcases()
{
    int n;
    cin>>n>>m;

    iv(arr,n);

    leftSums.clear();
    rightSums.clear();

    solve(0,n/2,arr,0);
    solve1(n/2,n,arr,0);

    sort(rightSums.begin(),rightSums.end());

    ll ans =0;

    for(auto & x:leftSums){

            //auto it = upper_bound(rightSums.begin(), rightSums.end(), m-1-x);
            auto it = lower_bound(rightSums.begin(), rightSums.end(), m-x);
        
            if (it != rightSums.begin()) {
                auto prev = it - 1;
                ll curr=x+*prev;
                curr=curr%m;
                ans = max(ans, curr);
            }

            ans = max(ans, (x + rightSums.back()) % m);
        }

        cout<<ans<<"\n";
}

int main()
{
    fast_io;
    int tt=1;
    //cin >> tt;
    while(tt--)
    {
        Testcases();
    }
}