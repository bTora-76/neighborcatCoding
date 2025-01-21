#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n = 3;
  int start = 0;
  int end = 2;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<float> weight = {0.5, 0.5, 0.2};

  vector<vector<pair<int, float>>> adj(n);

  priority_queue<pair<int, float>, vector<pair<int, float>>, greater<pair<int, float>>> pq;

  vector<float> dst(n, 0);

  //transfer from edges, weight to adj

  for (int i = 0; i < edges.size(); i++){
    adj[edges[i][0]].push_back({edges[i][1], weight[i]});
    adj[edges[i][1]].push_back({edges[i][0], weight[i]});
    }

  // process

    pq.push({start, 1.0});
    dst[start] = 1.0;

    while(!pq.empty()){
      int v = pq.top().first;
      float w = pq.top().second;

      pq.pop();

      for (int i = 0; i < adj[v].size(); i++){
        // w = เลขบน node ตัวที่ + ด้วยคือ weight ของ edge
        if ( w * adj[v][i].second > dst[adj[v][i].first]){
          dst[adj[v][i].first] = w * adj[v][i].second;
          pq.push({adj[v][i].first, w * adj[v][i].second});
        }
      }
    }

    for (int i = 0; i < n; i++){
      cout << dst[i] << '\n';
    }

      return 0;
}