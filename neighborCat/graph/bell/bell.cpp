#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int inf = 1e9 + 7;

int main(){
  int node, edge;
  int data[edge][3];
  cin >> node >> edge;

  int dst[node];
  for (int i = 0; i < node; i++){
    dst[i] = inf;
  }

  dst[0] = 0;
//   vector <pair <pair<int,int>,int>>

  for (int i = 0; i < edge; i++){
    cin >> data[i][0] >> data[i][1] >> data[i][2];
  }

    int a,b,w;

  // process
  // worst case scenerio will garentee node - 1 to update all nodes


  for(int i = 0; i < node - 1; i++){
    //j is row
    bool flag = false;

    for (int j = 0; j < edge; j++){
        a = data[j][0];
        b = data[j][1];
        w = data[j][2];
        if(dst[a]+w < dst[b]){
          flag = true;
          dst[b] = dst[a] + w;
        }
    }

    // optimize
    if(!flag){
      break;
    }
    
  }

  

  for (int j = 0; j < edge; j++){
        a = data[j][0];
        b = data[j][1];
        w = data[j][2];
        if(dst[a]+w < dst[b]){
          cout << "negative cycle" << '\n';
          return 0;
        }
    }

    for (int i =0; i < node; i++){
        cout << "Node " << i << ": " << dst[i] << '\n';
    }

}
