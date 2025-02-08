#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, goal;
  cin >> n >> goal;

  vector<pair<int, int>> v(n); // {value, og index};

  for (int i = 0; i < n; i++){
    cin >> v[i].first;
    v[i].second = i + 1;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++){
    int pivot = v[i].first;
    int subGoal = goal - pivot;
    int L, R;
    // if at start
    if (i == 0){
      L = 1;
      R = n - 1;
    }
    else if (i == n-1){
      L = 0;
      R = n - 2;
    }
    // if pivot is between numbers
    else{
      L = 0;
      R = n - 1;
    }

    // i serves as mid
    while (L < i && R > i){
      int sum = v[L].first + v[R].first;
      //cout << "Pivot: " << pivot << " " << v[L].first << " " << v[R].first << " Sum: " << sum << '\n';
      if (sum== subGoal){
        cout << v[L].second << " " << v[i].second << " " << v[R].second;
        return 0;
      }
      else if (sum < subGoal){
        ++L;
      }
      else if (sum > subGoal){
        --R;
      }
    }


  }

  cout << "IMPOSSIBLE";
  return 0;
}