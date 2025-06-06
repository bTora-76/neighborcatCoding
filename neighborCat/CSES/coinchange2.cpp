#include <iostream>
#include <vector>
using namespace std;
 
const int mod = 1e9 + 7;

int main(){
    int n,amount;
    cin >> n >> amount;
   
    vector<int> coins(n);
    vector <vector <int>> dp(n+1, vector <int>(amount+1,0)); // -1 = ยังไม่มี
    
    //input
    for (int i = 0; i < n;i++){
      cin >> coins[i];
    }

    for (int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    //process
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= amount; j++){
            dp[i][j] = dp[i-1][j];

            if(j-coins[i-1] >= 0){
                dp[i][j] = (dp[i][j] + dp[i][j-coins[i-1]]) % mod ; //add then mod
                // dp[i][j] += (dp[i][j-coins[i-1]] % mod) ; // mod before add
            }
        }
    }
   
   
   
    cout << dp[n][amount]; 
   
  }
  