#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;



int main(){
    
    vector <int> coins;
    int coinCount, sum;

    cin >> coinCount >> sum;

    int dp[sum+1] = {};

    for (int i =0; i < coinCount; i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    dp[0] = 1;

    // actual working
    for (int i = 1; i <= sum; i++){
        // loop for each coin
        for (int j = 0; j < coinCount; j++){
            if(i-coins[j] >= 0){
                dp[i] += dp[i-coins[j]] ;
                dp[i] %= mod;
            }
        }
    }


    cout << dp[sum];
}