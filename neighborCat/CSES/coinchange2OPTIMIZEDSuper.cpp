#include <iostream>
#include <vector>
using namespace std;
 
const int mod = 1e9 + 7;

int main(){
    int n,amount;
    cin >> n >> amount;
   
    vector<int> coins(n);
    vector <int> dp(amount,0);
    //input
    for (int i = 0; i < n;i++){
      cin >> coins[i];
    }

    dp[0] = 1;

    //process
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= amount; j++){
            if(j-coins[i-1] >= 0){
                dp[j] = (dp[j] + dp[j-coins[i-1]]) % mod;
            }
        }
    }
   
   
   
    cout << dp[amount]; 
   
  }
  