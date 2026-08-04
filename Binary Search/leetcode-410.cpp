// binary search on answers 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(vector<int>&arr,int k,int maxTime){
        
        int painter=1;
        int curr=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxTime) return false;
            
            if(curr+arr[i]>maxTime){
                painter++;
                curr=arr[i];
            }
            else curr+=arr[i];
        }
        
        return painter<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int mx=*max_element(nums.begin(),nums.end());
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        int l=mx;
        int r=sum;
        
        while(l<r){
            int mid=(l+r)/2;
            
            if(check(nums,k,mid)){
                
                r=mid;
            }
            else l=mid+1;
        }
        
        return r;
    }
};
