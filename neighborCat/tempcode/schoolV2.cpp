#include <iostream>
#include <vector>
using namespace std;

int mp[51][51];





int main(){

  int m, n;
  cin >> m >> n;
  int c;

  vector<vector<long long>> dp (n+1, vector<long long> (m+1, 0));
  vector<vector<bool>> dogs(n + 1, vector<bool>(m + 1, false));

  dp[1][1] = 1;

  cin >> c;
  for (int i = 0; i < c; i++){
    int x, y;
    cin >> x >> y;
    dogs[y][x] = true;
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      // if is dog
      if (dogs[i][j] == true || (i == 1 && j ==1)) continue;

      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }


  // for (int i = 1; i <= n; i++){
  //   for (int j = 1; j <= m; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  cout << dp[n][m];
}