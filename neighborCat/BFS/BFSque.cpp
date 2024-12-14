#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int node, edge, num1, num2;

int visited[100] = {0};
queue<int> myqueue;

int main(){
  

  cin >> node >> edge;

  vector<vector<int>> adj(node);

  for (int i = 0; i < edge; i++){
    cin >> num1 >> num2;
    adj[num1].push_back(num2);
    adj[num2].push_back(num1);
  }

  int start, end;
  cin >> start >> end;

  myqueue.push(start);
  visited[start]= 1;

  while(!myqueue.empty()){
    int t = myqueue.front();
    // cout << t;
    myqueue.pop();

    vector<int>::iterator it;
    // begin, end are pointer of the address of the first elements
    for (it = adj[t].begin(); it != adj[t].end(); it ++){
      if (visited[*it] == 0){
        visited[*it] = visited[t] + 1;
        myqueue.push(*it);
      }
      
    }
  }

  cout << visited[end] - 1;

  return 0;
}