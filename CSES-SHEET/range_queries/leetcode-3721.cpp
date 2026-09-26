#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

vector<int>segMin,segMax,lazy;
int n;

void propogate(int i,int l,int r){
    if(lazy[i]!=0){
        segMin[i]+=lazy[i];
        segMax[i]+=lazy[i];
        if(l!=r){
        lazy[2*i+1]+=lazy[i];
        lazy[2*i+2]+=lazy[i];
    }
    lazy[i]=0;
    }
}

void update(int i,int l,int r,int a,int b,int k){
    propogate(i,l,r);

    if(b<l || a>r) return;
    if(l>=a && r<=b){
        lazy[i]+=k;
        propogate(i,l,r);
        return;
    }

    int mid=(l+r)/2;

    update(2*i+1,l,mid,a,b,k);

    update(2*i+2,mid+1,r,a,b,k);

    propogate(2*i+1, l, mid);

    propogate(2*i+2, mid+1, r);

    segMin[i] = min(segMin[2*i+1],segMin[2*i+2]);
    segMax[i] = max(segMax[2*i+1],segMax[2*i+2]);
}

int find(int i,int l,int r){
    propogate(i,l,r);

    if(segMin[i]>0 || segMax[i]<0) return -1;

    if(l==r) return l;

    int mid=(l+r)/2;
    int p1=find(2*i+1,l,mid);

    if(p1!=-1) return p1;
    else return find(2*i+2,mid+1,r);
}

    int longestBalanced(vector<int>& nums) {
        n=nums.size();

        segMin.resize(4*n,0);
        segMax.resize(4*n,0);

        lazy.resize(4*n,0);

        int maxi=0;
        vector<int>prefix(n,0);
        unordered_map<int,int>mp;

        for(int r=0;r<n;r++){
            int val=(nums[r]%2==0) ? 1:-1;
            int prev=-1;
            if(mp.count(nums[r])) prev=mp[nums[r]];
            if(prev!=-1){
                update(0,0,n-1,0,prev,-val); //logn
            }
            
            update(0,0,n-1,0,r,val);
        
            int idx=find(0,0,n-1);
            if(idx!=-1) maxi=max(maxi,r-idx+1);
            mp[nums[r]]=r;
        }
        
        return maxi;

    }
};

