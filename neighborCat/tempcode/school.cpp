#include <iostream>
#include <vector>
using namespace std;

int mp[51][51];


long long f(int row, int col, vector<vector<long long>> &dp){
  // jump then check
  // basecase 

  if (row == 0 || col == 0){
    return 0;
  }

  if (row == 1 && col == 1){
    return 1;
  }

  if (mp[row][col] == 1){
    return 0;
  }

  if (dp[row][col] != -1){
    return dp[row][col];
  }

  // choice
  return dp[row][col] = f(row - 1, col,dp) + f(row, col - 1,dp);
}



int main(){

  int m, n;
  cin >> m >> n;
  int c;

  vector<vector<long long>> dp (n+1, vector<long long> (m+1, -1));

  

  cin >> c;
  for (int i = 0; i < c; i++){
    int x, y;
    cin >> x >> y;
    mp[y][x] = 1;
  }

  cout << f(n, m, dp);
}