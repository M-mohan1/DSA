#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n1=nums2.size();
        int n2=nums1.size();
        int B=ceil(float(sqrt(n1)));

        vector<long long>nums(nums2.begin(),nums2.end());

        unordered_map<int ,int>cnt1;
        for(auto &x:nums1){
            cnt1[x]++;
        }

        vector<unordered_map<long long ,long long >>cnt2(B);
        vector<long long>lazy(B);

        for(int i=0;i<n1;i++){
            cnt2[i/B][nums[i]]++;
        }

        auto update = [&](int block_idx, int start, int end, int val) {
            for (int i = start; i <= end; i++) {
                cnt2[block_idx][nums[i]]--;
                if (cnt2[block_idx][nums[i]] == 0) {
                    cnt2[block_idx].erase(nums[i]);
                }
                nums[i] += val;
                cnt2[block_idx][nums[i]]++;
            }
        };

        vector<int>result;
        for(auto &q:queries){
            int type=q[0];
            if(type==1){
                int q1=q[1];
                int q2=q[2];
                int val=q[3];

                int block_q1=q1/B;
                int block_q2=q2/B;

                if(block_q1==block_q2){
                    update(block_q1,q1,q2,val);
                }
                else{
                    update(block_q1, q1, (block_q1 + 1) * B - 1, val);
                    update(block_q2, block_q2 * B, q2, val);

                    for (int i = block_q1 + 1; i < block_q2; i++) {
                        lazy[i] += val;
                    }
                }
            }
            else{
                int tot = q[1];
                int total_pairs = 0;
            
                for (auto& [x, freq1] : cnt1) {
                    for (int i = 0; i < B; i++) {
                        long long target = (long long)tot - x - lazy[i];
                        if (cnt2[i].count(target)) {
                            total_pairs += cnt2[i][target] * freq1;
                        }
                    }
                }
                result.push_back(total_pairs);
            }
        }
        return result;
    }
};