#include <bits/stdc++.h>
using namespace std;

    class Solution {
    public:

    int rmiq(int idx,int l,int r,int a,int b,vector<int>&seg,vector<int>&arr){
        if (a > r || b < l)
            return -1;
        if(a <= l && r <= b) return seg[idx];
        int mid = (l + r) / 2;
        int p1 = rmiq(2*idx+1, l, mid, a, b,seg,arr);
        int p2 = rmiq(2*idx+2, mid+1, r, a,b,seg,arr);
        if(p1==-1) return p2;
        if(p2==-1) return p1;
        if(arr[p1]>arr[p2]) return p1;
        else return p2;
    }


    void build(int idx,int l,int r,vector<int>&arr,vector<int>&seg){
        if(l==r){
            seg[idx]=l;
            return;
        }
        int mid=(l+r)/2;
        build(2*idx+1,l,mid,arr,seg);
        build(2*idx+2,mid+1,r,arr,seg);
        if(arr[seg[2*idx+1]]>arr[seg[2*idx+2]]) seg[idx]=seg[2*idx+1];
        else seg[idx]=seg[2*idx+2];
    }
        
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();

        vector<int>seg(4*n);
        vector<int>ans;

        build(0,0,n-1,heights,seg);

        for(auto it:queries){
            int mini=min(it[0],it[1]);
            int maxi=max(it[0],it[1]);

            if(mini==maxi) ans.push_back(mini);
            else if(heights[maxi]>heights[mini]) ans.push_back(maxi);
            else{
                int l=maxi+1;
            int r=n-1;
            int idx=INT_MAX;

            while(l<=r){
                int mid=l+(r-l)/2;
                int p1=rmiq(0,0,n-1,l,mid,seg,heights);
                if(heights[p1]>max(heights[mini],heights[maxi])) {
                    idx=p1;
                    r=mid-1;
                }
                else l=mid+1;
            }

            if(idx==INT_MAX) ans.push_back(-1);
            else ans.push_back(idx);
        }
    }

        return ans;
        
    }
};
