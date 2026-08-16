#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int n,m;

int dx[3]={0,-1,-1};
int dy[3]={-1,0,-1};

int dp[101][101];
int cntDp[101][101];

const int mod=1e9+7;

    int solve(int i,int j,vector<string>&b){
        if(i==0 && j==0){
            return dp[i][j]=0 ;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int max_next=-2;

        for(int k=0;k<3;k++){
            int nx=i+dx[k];
            int ny=dy[k]+j;

            if(nx>=0 && ny>=0 && nx<n && ny<m && b[nx][ny]!='X'){
                int nextScore=solve(nx,ny,b);

                if (nextScore != -2) {
                    max_next = max(max_next, nextScore);
                }
            }
        }

        if (max_next == -2) {
            return dp[i][j] = -2;
        }

        int current_val = 0;

        if (isdigit(b[i][j])) {
            current_val = b[i][j] - '0';
        }

        return dp[i][j] = max_next + current_val;
    }

    int cnt(int i,int j,vector<string>&b){
        if(i==0 && j==0){
            return 1;
        }

        if(cntDp[i][j]!=-1) return cntDp[i][j];

        long long  ways=0;
        int current_val = 0;
        if (isdigit(b[i][j])) {
            current_val = b[i][j] - '0';
        }

        for(int k=0;k<3;k++){
            int nx=i+dx[k];
            int ny=dy[k]+j;

            if(nx>=0 && ny>=0 && nx<n && ny<m && b[nx][ny]!='X'){
                if (dp[nx][ny] != -1 && dp[nx][ny] + current_val == dp[i][j]) {
                    ways = (ways + cnt(nx, ny, b)) % mod;
                }
            }
        }

        return cntDp[i][j]=ways;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        m=board[0].size();

        memset(dp,-1,sizeof(dp));
        memset(cntDp,-1,sizeof(cntDp));

        int max_score =  solve(n-1,m-1,board);

        if (max_score == -2) {
            return {0, 0};
        }

        int ways=cnt(n-1,m-1,board);

        return {max_score,ways};
    }
};