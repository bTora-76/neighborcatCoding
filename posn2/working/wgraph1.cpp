#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, e, u ,v;
    cin >> n >> e >> u >> v;

    vector <vector <pair<int,int>>> adj(n+1);
    vector <int> dst(n+1, 1e9);

    for (int i = 1; i <= e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }


    // process dijkstra

    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,u});
    dst[u] = 0;

    while (!pq.empty()){
        int w = pq.top().first;
        int v = pq.top().second;

        pq.pop();

        vector <pair<int,int>>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++){
            if(w + it->second < dst[it->first]){    
                dst[it->first] = w + it->second;
                pq.push({ w + it->second, it->first});
            }
        }


    }
    // cout << (dst[v] = 1e9 ? -1 : dst[v]);
    if (dst[v] != 1e9){
        cout << dst[v];
    }
    else {cout << -1;}
    
    return 0;

}