#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
//   // make sure to process highest weights first
//   return a.first > b.first;
// }

// get parent function
int f(int n,  vector<int> & v){

  // basecase 
  if (v[n] == n)
    return n;

  // choice

  return v[n] = f(v[n], v);
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  
  vector<pair<int, pair<int, int>>> inputs;

  int n, e;
  long long cost;
  cin >> n >> e;
  cost = 0;

  for (int i = 0; i < e; i++){
    int a, b, w;
    cin >> a >> b >> w;
    inputs.push_back({w, {a, b}});
  }
  
  //descending order
  sort(inputs.begin(), inputs.end(), greater<pair<int, pair<int, int>>>());

  vector<int> parent (n+1);

  for (int i = 1; i <= n; i++){
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
    }
  }

  cout << cost - (n-1);
}