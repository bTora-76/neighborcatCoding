#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int node, edge, num1, num2;

bool visited[100];
stack<int> myStack;

int main(){
  

  cin >> node >> edge;

  vector<vector<int>> adj(node);

  for (int i = 0; i < edge; i++){
    cin >> num1 >> num2;
    adj[num1].push_back(num2);
    adj[num2].push_back(num1);
  }

  myStack.push(0);
  visited[0] = true;

  while(!myStack.empty()){
    int t = myStack.top();
    cout << t;
    myStack.pop();

    vector<int>::iterator it;
    // begin, end are pointer of the address of the first elements
    for (it = adj[t].begin(); it != adj[t].end(); it ++){
      if (visited[*it] == false){
        visited[*it] = true;
        myStack.push(*it);
      }
      
    }
  }

  return 0;
}