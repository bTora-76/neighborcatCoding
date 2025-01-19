#include <iostream>
#include <vector>
using namespace std;

int f(int n,  vector<int> & v){

  // basecase 
  if (v[n] == n)
    return n;

  // choice

  return v[n] = f(v[n], v);
}

int main(){
  vector<int> parent = {2, 3, 1, 4, 4, 4};

  cout << f(0, parent);
}