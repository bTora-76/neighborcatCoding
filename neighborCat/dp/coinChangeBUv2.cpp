// เลือกไม่เลือก
#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;



int main(){
    
    vector <int> coins;
    int coinCount, sum;

    cin >> coinCount >> sum;

    for (int i = 0; i < coinCount; i++){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }

    int dp [coinCount+1][sum+1] = {};

    

    // initialize

    for(int i = 0; i <= sum; i++){
        dp[0][i] = 0;
    }

    for (int i = 0; i <= coinCount; i++){
        dp[i][0] = 1;
    }

    

    // bottom up

    for(int i = 1; i <= coinCount; i++){
        for (int j = 1; j <= sum; j++){
            // check border
            if(j-coins[i-1] >= 0){
                dp[i][j] = (dp[i][j-coins[i-1]] % mod);
            }

            dp[i][j] += (dp[i-1][j] % mod);
            
        }
    }

   

    cout << dp[coinCount][sum];
}

//  for (int i = 0; i < coinCount+1; i++){
//         for (int j = 0; j < sum+1; j++){
//             cout << dp[i][j];
//         }
//         cout << '\n';
//     }