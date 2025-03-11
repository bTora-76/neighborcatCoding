#include <iostream>
using namespace std;

int mem[1000000];
const int inf = 500000000;

int f(int n){
  // basecase

  //dp

  if (mem[n] != inf){
    return mem[n];
  }

  if (n <= 0){
    return 0;
  }

  // choice

    return mem[n] = min(f(n - 15) + 3000, min(f(n - 5) + 1500, min(f(n - 2) + 800, f(n - 1) + 500)));
}

int main(){
  int n;
  cin >> n;

  for (int i =0; i <= n; i++){
    mem[i] = inf;
  }

  cout << f(n);
}