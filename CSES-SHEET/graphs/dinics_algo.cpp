#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int to, cap, rev;
};

class Dinic{
    int n;
    vector<vector<Edge>> g;
    vector<int> level, ptr;

public:
    Dinic(int n){
        this->n = n;
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void addEdge(int u,int v,int cap){
        Edge a = {v, cap, (int)g[v].size()};
        Edge b = {u, 0,   (int)g[u].size()};

        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs(int s,int t){
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(s);
        level[s]=0;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto &e:g[u]){
                if(level[e.to]==-1 && e.cap>0){
                    level[e.to]=level[u]+1;
                    q.push(e.to);
                }
            }
        }

        return level[t]!=-1;
    }

    int dfs(int u,int t,int flow){
        if(u==t || flow==0) return flow;

        for(int &i=ptr[u]; i<g[u].size(); i++){
            Edge &e=g[u][i];

            if(level[e.to]!=level[u]+1 || e.cap==0)
                continue;

            int pushed=dfs(e.to,t,min(flow,e.cap));

            if(pushed){
                e.cap-=pushed;
                g[e.to][e.rev].cap+=pushed;
                return pushed;
            }
        }

        return 0;
    }

    int maxflow(int s,int t){
        int flow=0;

        while(bfs(s,t)){
            fill(ptr.begin(), ptr.end(), 0);

            while(int pushed=dfs(s,t,1e9))
                flow+=pushed;
        }

        return flow;
    }
};

int main(){
    Dinic d(6);

    d.addEdge(0,1,16);
    d.addEdge(0,2,13);
    d.addEdge(1,2,10);
    d.addEdge(1,3,12);
    d.addEdge(2,1,4);
    d.addEdge(2,4,14);
    d.addEdge(3,2,9);
    d.addEdge(3,5,20);
    d.addEdge(4,3,7);
    d.addEdge(4,5,4);

    cout << d.maxflow(0,5);
}