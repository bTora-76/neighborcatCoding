#include <iostream>
#include <vector>
using namespace std;

// find parent
int f(int n,  vector<int> & v){

  // basecase 
  // if the value of is equal to its index, then it is parent
  if (v[n] == n)
    return n;

  // choice

  return v[n] = f(v[n], v);
}

int main(){
  vector<int> parent = {0,1,2,3,4};
  int n, e;
  cin >> n >> e;

  for (int i = 0; i < e; i++){
    int a, b;
    cin >> a >> b;

    int A = f(a, parent);
    int B = f(b, parent);

    if (A!=B){
      parent[A] = B;
    }
  }

  for (int i = 0; i <= n; i++){
    cout << f(parent[i], parent) << '\n';
  }
}