#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

bool comp(pii a, pii b){
    return (a.first> b.first);
}

int main(){
    int coinNums,amount;
    cin >> coinNums;

    vector <pii> coins(coinNums);

    for (int i = 0; i < coinNums; i++){
        int temp;
        cin >> temp;
        coins[i] = {temp, 0}; // coin, count
    }

    sort(coins.begin(), coins.end(), comp);

    cin >> amount;

    int i = 0;
    int total = 0;

    while (amount > 0){
        // greedy will use the maximum of the largest coins first (what i did in posn1)
        int remainder = amount % coins[i].first;
        int thisCount = amount/coins[i].first;
        coins[i].second = thisCount;
        ++i; 
        total += thisCount;
        amount = remainder;
    }


    cout << total << '\n';

    for (int i = 0; i < coinNums; i++){
        for (int j = 0; j < coins[i].second; j++){
            cout << coins[i].first << " ";
        }
    }





}