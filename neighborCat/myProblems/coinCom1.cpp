#include <iostream>
#include <vector>
using namespace std;

long long coinCount,sum;



long long f(long long s, vector <long long> &coins, vector <long long> &dp){
    //base case

    if(s == 0) return 1;
    if (s < 0) return 0;

    //dp
    if(dp[s] != -1) return dp[s];

    // choice
    long long ways = 0;

    for(long long i = 0; i < coinCount; i++){;
        ways = (ways + f(s-coins[i], coins, dp) % 1000000007); 
    }

    dp[s] = ways % 1000000007;

    return ways % 1000000007;

}


int main(){

    vector <long long> dp (10000000,-1);

    vector <long long> coins;
    cin >> coinCount >> sum;

    for (long long i = 0; i < coinCount; i++){
        long long temp;
        cin >> temp;
        coins.push_back(temp);
    }

    cout << f(sum, coins, dp);

    return 0;
}