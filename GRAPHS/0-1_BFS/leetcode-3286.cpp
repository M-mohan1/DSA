#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,INT_MAX));

        deque<pair<int,int>>q;
        q.push_back({0,0});
        vis[0][0]=grid[0][0];

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop_front();

            if(x==n-1 && y==m-1) return true;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && ny>=0 && nx<n && ny<m){

                    int cost=vis[x][y]+grid[nx][ny];
                    if(cost>=health) continue;

                    if(vis[nx][ny]>cost) {
                        vis[nx][ny]=cost;

                        if(grid[nx][ny]==0) q.push_front({nx,ny});
                        else {
                    q.push_back({nx,ny});
                        }
                    }
                }
            }
        }

        return false;
    }
};