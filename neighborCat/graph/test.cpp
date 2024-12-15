#include <iostream>
#include <vector>
using namespace std;

vector < vector<int>> adj(100);

vector <bool> visited(100, false);

void f(int pos){
    if(visited[pos] == true)return;
    
    visited[pos] = true;

    for (int i = 0; i < adj[pos].size(); i++){
        f(adj[pos][i]);
    }
}

int main(){ 
    int nodes, edges, num1, num2;
    // allocate memory for visited
    cin >> nodes >> edges;

    // input
    for(int i = 0; i < edges; i++){
        cin >> num1 >> num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }

    // print accessibility of each node

    f(0);

    for (int i = 0; i < nodes; i++){
        cout << "Node " << i << ": " << visited[i] << '\n';
    }
        




    return 0;
}