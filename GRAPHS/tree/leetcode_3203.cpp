#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:

    vector<vector<int>>adj1;
    vector<vector<int>>adj2;
    int ans ;
    
    int getDiameter1(int u,int parent){
        int mx1=0;
        int mx2=0;

        for(auto & v:adj1[u]){
            if(v==parent) continue;

            int d=getDiameter1(v,u)+1;

            if(mx1<=d){
                mx2=mx1;
                mx1=d;
            }
            else if(d>mx2){
                mx2=d;
            }
        }

        ans=max(ans,mx1+mx2);
        return mx1;
    }

    int getDiameter2(int u,int parent){
        int mx1=0;
        int mx2=0;

        for(auto & v:adj2[u]){
            if(v==parent) continue;

            int d=getDiameter2(v,u)+1;

            if(mx1<=d){
                mx2=mx1;
                mx1=d;
            }
            else if(mx2<d){
                mx2=d;
            }
        }

        ans=max(ans,mx1+mx2);
        return mx1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n=edges1.size()+1;
        int m=edges2.size()+1;

        adj1.resize(n);
        adj2.resize(m);

        for(auto &it:edges1){
            int u=it[0];
            int v=it[1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(auto &it:edges2){
            int u=it[0];
            int v=it[1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        ans=0;
        getDiameter1(0,-1);
        int d1=ans;

        ans=0;
        getDiameter2(0,-1);
        int d2=ans;

        return max({d1,d2,(d1+1)/2+(d2+1)/2+1});
    }
};