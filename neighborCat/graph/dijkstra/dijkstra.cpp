#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int inf = 1e9 + 7;

int main(){
  int node, edge;
  cin >> node >> edge;

  vector <vector <pair <int,int>>> adj(node);

  priority_queue<pair <int,int>, vector<pair <int,int>>, greater<pair <int,int>>> pq;

  vector<int> dst(node, inf);

  for (int i = 0; i < edge; i++){
    int node1, node2, w;
    cin >> node1 >> node2 >> w;
    adj[node1].push_back({node2,w});
    adj[node2].push_back({node1,w});
  }

  // dijksttra

  pq.push({0, 0}); // starting node
  dst[0] = 0;

  while (!pq.empty()){
    int w = pq.top().first;
    int v = pq.top().second;

    pq.pop();

    //loop all neighbors
    vector<pair<int, int>>::iterator it;

    for (it = adj[v].begin(); it != adj[v].end(); it++){
      // if less than, add
      if ( w + it->second < dst[it->first]){
        pq.push({w + it->second, it->first}); // all distances here are in relation to the starting node 
        dst[it->first] = w + it->second;
      }

    }
  }

  
  for (int i = 0; i < node; i++){
    cout << dst[i] << '\n';
  }
}
