#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  // bangkok = node 0
  // goal = node 1
  const int inf = 1e9 + 7;

  int node, edge;
  cin >> node;
  cin >> edge;

  vector<vector<pair<int, int>>> adj(node+1);
  vector<int> dst(node + 1, inf);
  priority_queue<pair <int,int>, vector<pair <int,int>>, greater<pair <int,int>>> pq;

  // japan
  for (int i = 0; i < edge; i++){
    int a, b, weight;
    cin >> a >> b >> weight;
    ++a;
    ++b;
    
    adj[a].push_back({b, weight});
    adj[b].push_back({a, weight});
  }

  //bangkok
  int edge2;
  cin >> edge2;
  for (int i = 0; i < edge2; i++){
    int a, b, weight;
    cin >> b >> weight;
    ++b;
    adj[0].push_back({b, weight});
    adj[b].push_back({0, weight});
  }

  // dijkstra

  pq.push({0, 0});
  dst[0] = 0;

  // use the convention so that only small weight has to be done >> optimized
  while (!pq.empty()){
    int w = pq.top().first;
    int v = pq.top().second;

    pq.pop();

    //loop neighbors
    // node have 0 - n must use <=
    for (int i = 0; i < adj[v].size(); i++){
      if ( w + adj[v][i].second < dst[adj[v][i].first] ){
        dst[adj[v][i].first] = w + adj[v][i].second;
        pq.push({w + adj[v][i].second, adj[v][i].first});
      }
    }
  }


  cout << dst[1];

  return 0;
}