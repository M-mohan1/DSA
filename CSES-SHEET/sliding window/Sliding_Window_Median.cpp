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
                
vector<int> slidingWindowMedian(vector<int>& nums, int X) {
    vector<int> medians;
    multiset<int> left, right;
    int i = 0, j = 0, n = nums.size();

    while (j < n) {
        // Insert new element into the sliding window
        if ((int)left.size() <= (int)right.size()) {
            left.insert(nums[j]);
        } else {
            right.insert(nums[j]);
        }

        int leftSize = left.size();
        int rightSize = right.size();

        // Balance multisets to maintain median
        while (leftSize > 0 && rightSize > 0) {
            int leftMax  = *left.rbegin();
            int rightMin = *right.begin();
            if (leftMax > rightMin) {
                // Swap elements to restore balance
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
            int median = *left.rbegin();
            medians.push_back(median);
            
            // Remove the leftmost element as we slide forward
            if (left.find(nums[i]) != left.end()) {
                left.erase(left.find(nums[i]));
            } else {
                right.erase(right.find(nums[i]));
            }
            i++;
        }
        j++;
    }
    return medians;
}

void Testcases()
{
    int n,k;
    cin>>n>>k;
    iv(arr,n);

    vector<int>ans=slidingWindowMedian(arr,k);
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