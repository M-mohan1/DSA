#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,-1)) ;
        queue<vector<int>>q;
        q.push({0,0,0,k});

        vis[0][0]=0;
        while(!q.empty()){

            auto it=q.front();
            q.pop();

            int x=it[0];
            int y=it[1];
            int steps=it[2];
            int curr=it[3];

            if(x==n-1 && y==m-1)
            return steps;

            for(int i=0;i<4;i++){

                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(vis[nx][ny]>=curr && vis[nx][ny]!=-1) continue;

                    else if(grid[nx][ny]==1){
                        if(curr>0){
                            q.push({nx,ny,steps+1,curr-1});
                            vis[nx][ny]=curr;
                        }
                        else continue;
                    }
                    else{
                        q.push({nx,ny,steps+1,curr});
                        vis[nx][ny]=curr;
                    }
                }
            }
        }

            return -1;
    }
};