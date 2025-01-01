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

  vector <int> dp(n+1); // account for 0
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i ++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  cout << dp[n];

  

  return 0;
}