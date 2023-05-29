#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> G[N];
bool visited[N];

void DFS(int vertex){
    visited[vertex] = 1;
    cout<<vertex<<" - ";
    for (auto i : G[vertex]) {
        if(!visited[i]){
            DFS(i);
        }
    }
}

void make_unvisited(){
    for (int i = 0; i < N; i++) {
        visited[i] = 0;
    }
}

void BFS(int vertex){
    queue<int>q;
    q.push(vertex);
    visited[vertex] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for (auto i : G[x]) {
            if(!visited[i]){
                q.push(i);
                visited[i] = 1; // mistake 
            }
        }
        cout<<x<<" ";
    }
}

int main()
{
    int v,e;
    cout<<"Enter No. of vertices and No. of edges : ";
    cin>>v>>e;
    cout<<"Enter source & destination of all edges"<<endl;
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    cout<<"From which vertex u want to start traversal : ";
    cin>>v;
    cout<<"DFS :- ";
    DFS(v);
    make_unvisited();
    cout<<"\nBFS :- ";
    BFS(v);
    return 0;
}