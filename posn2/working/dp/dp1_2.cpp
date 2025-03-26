#include <iostream>
#include <vector>
using namespace std;

vector <vector <int>> mem;

int f(int i, int a, vector<int> &v){
    
    if(a == 0) return 0;
    if(i < 0 || a < 0) return 0;

    return (max(f(i-1,a-v[i],v) + 1, f(i-1,a,v)));

}

int main(){
    int coinTypes, amount;
    cin >> coinTypes;

    

    vector <int> coins(coinTypes);

    for (int i = 0; i < coinTypes; i++){
        cin >> coins[i];
    }

    cin >> amount;

    mem.resize(coinTypes, vector<int>(amount,-1));

    cout << f(coinTypes-1, amount,coins);


}