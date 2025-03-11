#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int f(int amount,int index, vector <vector <int>> &mem, vector<int>& coins){
    if(amount == 0)
        return 1;
    if (amount < 0)
        return 0;
    if (index == 0) return 0;

    if(mem[amount][index] != -1) return mem[amount][index]; // dynamic

    // general choice


    // mem[amount][index] = sum; 


    return mem[amount][index] = f(amount - coins[index-1], index, mem,coins)  % mod + f(amount, index - 1, mem,coins)  % mod; // เลือก + ไม่เลือก
}

int main(){
  int n,amount;
  cin >> n >> amount;

  vector<int> coins(n);
  vector <vector <int>> mem(amount + 1, vector <int> (n + 1, -1)); // -1 = ยังไม่มี

  for (int i = 0; i < n;i++){
    cin >> coins[i];
  }
  

  int x = f(amount,n,mem,coins);



  cout << x % mod; 

}

