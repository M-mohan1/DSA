#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Unite(int x,int y){
        int p1=find(x);
        int p2=find(y);

        if(p1==p2) return ;

        if(rank[p1]>rank[p2]) parent[p2]=p1;
        else if(rank[p2]>rank[p1]) parent[p1]=p2;
        else{
            parent[p2]=p1;
            rank[p1]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();

        parent.resize(n);
        rank.assign(n,1);

        for(int i=0;i<n;i++) parent[i]=i;

        map<int,vector<int>>mp;
        vector<vector<int>>adj(n);

        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            int value=vals[i];
            mp[value].push_back(i);
        }

        int result = n;
        
        vector<bool> is_active(n, false); 
        
        for (auto &it : mp) {
            
            vector<int> nodes = it.second;
            
            for (int &u : nodes) {
                
                for (int &v: adj[u]) {
                    if (is_active[v]) {
                        Unite(u, v);
                    }
                }
                is_active[u] = true;
            }
            
            vector<int> tumhare_parents;
            
            for (int &u : nodes) 
                tumhare_parents.push_back(find(u));
            
            sort(tumhare_parents.begin(), tumhare_parents.end());
                        
            int sz = tumhare_parents.size();
            
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                
                int cur_parent = tumhare_parents[j];
                
                while (j < sz && tumhare_parents[j] == cur_parent) {
                    j++, 
                    count++;
                }
                j--;
                
                result += (count * (count - 1))/2;
            }
        }
        
        return result;



    }
};