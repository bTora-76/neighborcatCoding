#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f(int n,  vector<int> & v){

  // basecase 
  if (v[n] == n)
    return n;

  // choice

  return v[n] = f(v[n], v);
}

int main(){
  vector<pair<int, pair<int, int>>> inputs;

  int n, e, cost;
  cin >> n >> e;
  cost = 0;

  for (int i = 0; i < e; i++){
    int a, b, w;
    cin >> a >> b >> w;
    inputs.push_back({w, {a, b}});
  }

  sort(inputs.begin(), inputs.end());

  vector<int> parent (n);
  vector <int> edgesR;

  for (int i = 0; i < n; i++){
    parent[i] = i;
  }

  for (int i = 0; i < e; i++)
  {
    int a = inputs[i].second.first;
    int b = inputs[i].second.second;
    int w = inputs[i].first;

    int A = f(a, parent);
    int B = f(b, parent);

    if (A!=B){
      parent[A] = B; // เอา root มาเชื่อมกัน
      cost += w;
      edgesR.push_back(w);
    }
  }

  cout << cost << '\n';
  for (int i = 0; i < n; i++){
    cout << parent[i] << " ";
  }
  cout << '\n';
  for (int i = 0; i < n - 1; i++){
    cout << edgesR[i] << " ";
  }



}