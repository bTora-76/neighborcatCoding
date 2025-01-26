// dynamic: top down

#include <iostream>
#include <vector>
using namespace std;


int n;


int f(int n, vector <int> &v){
  if(n <= 1)
    return n;

  if (v[n] != -1){
    return v[n];
  }

  return v[n] = f(n - 1, v) + f(n - 2, v); // set v[n] and return f n-1 + f n-2
}



int main(){



  cin >> n;
  // vector<int> v(n + 1, -1);
  // cout << f(n,v);

  return 0;
}