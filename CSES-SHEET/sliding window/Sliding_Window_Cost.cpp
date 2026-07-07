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
                
vector<ll> slidingWindowMedian(vector<int>& nums, int X) {
    vector<ll> costs;
    multiset<ll> left, right;
    int i = 0, j = 0, n = nums.size();

    ll leftSum=0;
    ll rightSum=0;

    while (j < n) {
        // Insert new element into the sliding window
        if ((int)left.size() <= (int)right.size()) {
            left.insert(nums[j]);
            leftSum+=nums[j];
        } else {
            right.insert(nums[j]);
            rightSum+=nums[j];
        }

        int leftSize = left.size();
        int rightSize = right.size();

        // Balance multisets to maintain median
        while (leftSize > 0 && rightSize > 0) {
            int leftMax  = *left.rbegin();
            int rightMin = *right.begin();

            if (leftMax > rightMin) {
                // Swap elements to restore balance
                leftSum = leftSum - leftMax + rightMin;
                rightSum = rightSum - rightMin + leftMax;

                left.insert(rightMin); 
                right.insert(leftMax);

                left.erase(left.find(leftMax));
                right.erase(right.find(rightMin));

                leftSize = left.size();
                rightSize = right.size();

            } else {
                break;
            }
        }

        // Check if we have a valid subarray
        if (j - i + 1 == X) {
             ll median = *left.rbegin();
            
            ll current_cost=0;
            if (X % 2 == 0) {
                current_cost = rightSum - leftSum;
            } else {
                current_cost = rightSum - leftSum + median;
            }
            costs.push_back(current_cost);

            if (left.find(nums[i]) != left.end()) {
                left.erase(left.find(nums[i]));
                leftSum-=nums[i];
            } 
            else {
                right.erase(right.find(nums[i]));
                rightSum-=nums[i];
            }
            i++;
        }
        j++;
    }
    return costs;
}

void Testcases()
{
    int n,k;
    cin>>n>>k;
    iv(arr,n);

    vector<ll>ans=slidingWindowMedian(arr,k);

    for(auto &x:ans) cout<<x<<" ";
    cout<<"\n";
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