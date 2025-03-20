#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;

int getminIn(vector <int> &keys, vector <bool> &mstSet){
  int minIndex = -1;

  for (int i = 0; i < keys.size(); i++){
    
    // กันเป็น 0 ตลอดไป
    else if (minIndex == -1 || keys[i] < keys[minIndex]){
      minIndex = i;
    }
  }
  return minIndex;
}


int main(){
  int node, edge;
  cin >> node >> edge;

  int adj[node][node];

  for (int i = 0; i < node; i++){
    for (int j = 0; j < node; j++){
      adj[i][j] = 0;
    }
  }

  vector<int> keys(node, inf);
  keys[0] = 0;

  vector<bool> mstSet(node, false);

  vector<int> parent(node);
  parent[0] = -1;

  for (int i = 0; i < edge; i++){
    int node1, node2, w;
    cin >> node1 >> node2 >> w;
    adj[node1][node2] = w;
    adj[node2][node1] = w;
  }

  // process

  for (int i = 0; i < node; i++){
    int minIndex = getminIn(keys, mstSet);
    mstSet[minIndex] = true;
    // loop neighbor
    for (int j = 0; j < node; j++){
      // check visited
      if (mstSet[j] == false && adj[minIndex][j] != 0){
        if(adj[minIndex][j] < keys[j]){
          keys[j] = adj[minIndex][j];
          parent[j] = minIndex;
          
        }
      }
    }
  }

  // sum keys

  int sum = 0;
  for (int i = 0; i < node; i++){
    sum += keys[i];
  }

  cout << sum;

  // for (int i = 0; i < node; i++){
  //   cout << keys[i] << " ";
  // }
  return 0;
}
