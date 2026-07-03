/*
If someone has achieved it before, it means it's possible.
Every accepted solution was once a wrong answer.
The expert in anything was once a beginner.
*/
#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define rev(v) reverse(all(v))

#define ll long long
#define no cout<< "NO"<<endl;
#define yes cout<<"YES"<<endl;
#define pans cout<<ans<<endl;
#define pcnt cout<<cnt<<endl;

#define iv(v,n) vector<int>v(n); f(i,0,n) cin>>v[i]
#define f(i, a, b) for (int i = a; i < b; i++)
const int mod=1e9+7 ;
                


vector<vector<int>>ans;
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};

int countMoves(int x, int y){
    int cnt=0;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0  && ny>=0 && nx< 8 && ny<8 && ans[nx][ny]==-1)  cnt++;
    }

    return cnt ;
}

vector<tuple<int,int,int>> getSortedMoves(int x, int y) {

    vector<tuple<int,int,int>>Sorted;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && ans[nx][ny] == -1) {
            int moves = countMoves(nx, ny);
            Sorted.push_back({moves,nx,ny});
        }
    }

    // Sort using default vector<int> lexicographic comparison
    sort(Sorted.begin(), Sorted.end());

    return Sorted;
}


    bool dfs(int i,int j,int steps){
        if(steps==64) return true;
    
        vector<tuple<int,int,int>> moves = getSortedMoves(i,j);

    for (auto &it:moves) {
        auto[ways,InX,InY]=it;
        int nx =InX;
        int ny = InY;

        ans[nx][ny] = steps+1;
        if (dfs(nx, ny, steps + 1))
            return true;

        // Backtrack
        ans[nx][ny] = -1;
    }
    return false;
    }

void Testcases()
{
    int x,y;
    cin>>x>>y;
    ans.assign(8,vector<int>(8,-1));
    ans[y-1][x-1]=1;
    if(dfs(y-1,x-1,1)){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
int main()
{
    fast_io;
    int tt=1;
    while(tt--)
    {
        Testcases();
    }
}