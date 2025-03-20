#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, e;
    cin >> n >> e;

    vector <vector <pair<int,int>>> adj(n+1);
    vector <int> dst(n+1, 1e9);

    for (int i = 0; i < e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    int start, finish, k;
    cin >> start >> finish >> k;


    // process dijkstra

    priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    pq.push({0,{0,start}});
    dst[start] = 0;

    while (!pq.empty()){

        int w = pq.top().first;
        int t = pq.top().second.first;
        int v = pq.top().second.second;

        pq.pop();

        vector <pair<int,int>>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++){
            
            // if find finish
            if (w + it->second < dst[it->first] && it->first == finish){
                dst[it->first] = w + it->second;
                 pq.push({ w + it->second, { t,it->first}});
            }
            // if not find finish
            else if(w + it->second < dst[it->first] && t + 1 <= k){    
                dst[it->first] = w + it->second;
                pq.push({ w + it->second, { t+1,it->first}}); // add times that have walked
            }
            
        }
    }
    
    if (dst[finish] >= 1e9){
        cout << -1;
    }
    else {
        cout << dst[finish];
    }

    
   
    
    return 0;

}