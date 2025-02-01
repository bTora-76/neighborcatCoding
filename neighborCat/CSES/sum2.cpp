#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

  int n, goal;
  cin >> n >> goal;

  vector <pair <int,int>> v(n);  // {value, actual index before sorted}


  for (int i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  int L = 0, R = n - 1;

  while (L < R){
    // check if equal

    int sum = v[L].first + v[R].first;

    if (sum == goal){
      cout << v[L].second + 1<< " " << v[R].second + 1;
      return 0;
    }

    if(sum < goal){
      ++L;
    }

    else if (sum > goal){
      --R;
    }
  }

  cout << "IMPOSSIBLE";
  return 0;
}