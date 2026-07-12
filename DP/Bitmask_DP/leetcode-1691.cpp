#include<bits/stdc++.h>
using namespace  std;


class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int subset_size = n / k;
        
        if (subset_size == 1) return 0;

        vector<pair<int, int>> valid_subsets;
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) == subset_size) {
                vector<int> current_elements;
                bool has_duplicate = false;
                
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        current_elements.push_back(nums[i]);
                    }
                }
                
                sort(current_elements.begin(), current_elements.end());
                for (int i = 0; i < subset_size - 1; ++i) {
                    if (current_elements[i] == current_elements[i + 1]) {
                        has_duplicate = true;
                        break;
                    }
                }
                
                if (!has_duplicate) {
                    int cost = current_elements.back() - current_elements.front();
                    valid_subsets.push_back({mask, cost});
                }
            }
        }


        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0; 
        // Step 3: Run the Bitmask DP transitions
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == INT_MAX) continue; 
        
            if (__builtin_popcount(mask) % subset_size == 0) {
                
                for (const auto& subset : valid_subsets) {
                    int sub_mask = subset.first;
                    int cost = subset.second;
        
                    if ((mask & sub_mask) == 0) {
                        int next_mask = mask | sub_mask;
                        dp[next_mask] = min(dp[next_mask], dp[mask] + cost);
                    }
                }
            }
        }
        return dp[(1 << n) - 1] == INT_MAX ? -1 : dp[(1 << n) - 1];
    }
};