#include <iostream>
#include <vector>
using namespace std;

const int inf = 2000;

int adj[5][5];

void show(){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      cout << adj[i][j] << " ";
    }
    cout << '\n';
  }
}


int main(){

  int node, edge;
  cin >> node >> edge;

  // int adj[node][node];

  // default fill 0 and inf
  for (int i = 0; i < node; i++){
    for (int j = 0; j < node; j++){
      if (i == j){
        adj[i][j] = 0;
      }

      else{
        adj[i][j] = inf;
      }      
    }
  }

 

  // loop get input

  for (int i = 0; i < edge; i++){
    int s, e, w;
    cin >> s >> e >> w;
    adj[s][e] = w;
  }
  // process
	
  int k = 0;

  for (int k = 0; k < node; k++){
    for (int i = 0; i < node; i++)
    {
    for (int j = 0; j < node; j++){
       if (adj[i][k] != inf && adj[k][j] != inf){
        // should use if because inf + 1can be -inf
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);  
      }
    }
  }
  }

    show();
  cout << "Helelo";

  return 0;
}
