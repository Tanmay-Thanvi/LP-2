// -------------------------------- Selection sort --------------------------------

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cout<<"\nEnter number of elements: ";
//     cin>>n;
//     cout<<"\nEnter "<<n<<" numbers: ";
//     vector<int> v(n); 
//     for(int i = 0;i<n;i++){
//         cin>>v[i];
//     }
//     for(int i = 0;i<n;i++){
//         int mini = v[i];
//         int pos = i;
//         for(int j = i+1;j<n;j++){
//             if(mini>v[j]){
//                 mini = v[j];
//                 pos = j;
//             }
//         }
//         swap(v[i],v[pos]);
//     }
//     cout<<"\nAfter applying selection sort the array becomes: ";
//     for(int i = 0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
// }


// ------------------------------- Minimal spanning tree & Kruskal's algorithm ---------------------------

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> graph[1005];
// int is_loop = 0;

// void DFS(int vertex,int target,vector<int> &vis){
//     if(vertex==target){
//         is_loop = 1;
//         return;
//     }
//     vis[vertex] = 1;
//     for(auto child:graph[vertex]){
//         if(!vis[child]){
//             DFS(child,target,vis);
//         }
//     }
// }

// int main(){
//     int v;
//     cout<<"\nEnter number of vertices: ";
//     cin>>v;
//     cout<<"\nEnter number of edges: ";
//     int e;
//     cin>>e;
//     vector<pair<int,pair<int,int>>> vp;
//     for(int i = 0;i<e;i++){
//         cout<<"\nEnter edge and weight "<<i+1<<" : ";
//         int x,y,w;
//         cin>>x>>y>>w;
//         vp.push_back({w,{x,y}});
//     }
//     sort(vp.begin(),vp.end());
//     int ans=0;
//     cout<<"\nEdges present in minimal spanning tree are: \n";
//     for(auto x:vp){
//         int u = x.second.first;
//         int v = x.second.second;
//         int w = x.first;
//         vector<int> vis(v+1,0);
//         DFS(u,v,vis);
//         if(is_loop){
//             is_loop = 0;
//             continue;
//         }
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//         cout<<u<<" - "<<v<<endl;
//         ans+=w;
//     }
//     cout<<"\nCost of minimal spanning tree is: "<<ans<<endl;
//     return 0;
// }


// -------------------------- Single source shortest path problem ------------------


#include <bits/stdc++.h>
using namespace std; 

vector<pair<int,int>> g[1005];
int vis[1005];
int dist[1005];

void BFS(int vertex){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,vertex});
    vis[vertex]=1;
    while(!pq.empty()){
        int x = pq.top().second;
        pq.pop();
        for(auto ch:g[x]){
            if(dist[ch.first]>dist[x]+ch.second){
                dist[ch.first]=dist[x]+ch.second;
                vis[ch.first]=1;
                pq.push({dist[ch.first],ch.first});
            }
        }
    }
}

int main(){
    for(int i = 0;i<1005;i++){
        dist[i] = INT_MAX;
    }
    int v;
    cout<<"\nEnter number of vertices: ";
    cin>>v;
    int e;
    cout<<"\nEnter number of edges: ";
    cin>>e;
    for(int i = 0;i<e;i++){
        cout<<"\nEnter start point, end point and weight of edge "<<i+1<<" : ";
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    cout<<"\nEnter source vertex: ";
    int src;
    cin>>src;
    dist[src]=0;
    BFS(src); 
    for(int i = 1;i<=v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
