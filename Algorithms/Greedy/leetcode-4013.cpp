
/* 
    implimentation of merge sort .
    memorize this manipulation :-

    vector<ll> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            ll val = (nums[i] % 2 == 0) ? b : -a;
            prefix[i + 1] = prefix[i] + val;
        }

        see vivek  gupta lecture 

*/

#include<bits/stdc++.h>
using namespace  std ;

class Solution {
public:
    using ll = long long;

    ll merge(vector<ll>& arr, int low, int mid, int high) {
        int n1 = low;
        int n2 = mid + 1;

        vector<ll> temp;
        ll cnt = 0;

        while (n1 <= mid && n2 <= high) {
            
            if (arr[n1] < arr[n2]) {
                temp.push_back(arr[n1]);
                n1++;
            } else {
                temp.push_back(arr[n2]);
                cnt += (mid - n1 + 1);
                n2++;
            }
        }
        
        while (n1 <= mid) {
            temp.push_back(arr[n1]);
            n1++;
        }

        while (n2 <= high) {
            temp.push_back(arr[n2]);
            n2++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    ll mergeSort(vector<ll>& arr, int low, int high) {
        ll cnt = 0;
        if (low >= high)
            return cnt;

        int mid = low + (high - low) / 2;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        
        return cnt;
    }

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        

        vector<ll> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            ll val = (nums[i] % 2 == 0) ? b : -a;
            prefix[i + 1] = prefix[i] + val;
        }

        return mergeSort(prefix, 0, n);
    }
};