#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;

        deque<array<int, 3>> deque;
        deque.push_back({0, 0, 0});  // {obstacles, row, col}

        while (!deque.empty()) {
            auto current = deque.front();
            deque.pop_front();
            int d = current[0], x = current[1], y = current[2];

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if (nx>=0 && ny>=0 && nx<n &&  ny<m && dist[nx][ny] == INT_MAX) {
                    if (grid[nx][ny] == 1) {

                        dist[nx][ny] = d + 1;
                        deque.push_back({d + 1, nx, ny});
                    } else {
                        dist[nx][ny] = d;
                        deque.push_front({d,nx, ny});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }

private:
    // Helper method to check if the cell is within the grid bounds
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
            col < grid[0].size();
    }
};