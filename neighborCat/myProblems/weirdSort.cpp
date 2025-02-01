#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool comp(int a, int b){
  if (abs(a) == abs(b)){
    return a < b;
  }
  else {
    return abs(a) < abs(b);
  }
}

int main(){

  int n;
  cin >> n;

  vector<int> inputs(n);

  for (int i = 0; i < n; i++){
    cin >> inputs[i];
  }

  sort(inputs.begin(), inputs.end(), comp);

  for (int i : inputs){
    cout << i << " ";
  }

  return 0;
}