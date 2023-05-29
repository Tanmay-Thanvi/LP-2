#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> G[N];
vector<int> Dist(N,INF);
bool visited[N];

void Dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    Dist[src] = 0;
    pq.push({0,src});
    
    while(!pq.empty()){
        int node = pq.top().second; 
        int distance = pq.top().first;
        pq.pop();
        
        if(visited[node]) continue;
        visited[node] = true; 
        
        for (auto child : G[node]) {
            if(Dist[node]+child.second < Dist[child.first]){
                Dist[child.first] = Dist[node]+child.second;
                pq.push({Dist[child.first],child.first});
            }
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; i++) {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        G[v1].push_back({v2,wt});
        G[v2].push_back({v1,wt});
    }
    cin>>e;
    Dijkstra(e);
    
    for (int i = 0; i < v; i++) {
        cout<<Dist[i]<<" ";
    }
    return 0;
}