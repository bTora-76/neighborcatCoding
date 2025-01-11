#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
  vector <pair <int,int>> adj;

  priority_queue<int, vector<int>, greater<int>> pq;

  pq.push(0);
  pq.push(5);
  pq.push(3);
  pq.push(8);
  pq.push(1);

  while (!pq.empty()){
    cout << pq.top();
    pq.pop();
  }
}