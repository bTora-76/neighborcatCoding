#include <iostream>
#include <vector>
using namespace std;

vector<int> coins = {1,2,5};


int n;

int f(int amount,int index, vector <vector <int>> &mem){
  if(amount == 0)
    return 1;
  if (amount < 0)
    return 0;
  if(mem[amount][index] != -1) return mem[amount][index];

  int sum = 0;
  for (int i = index; i < coins.size(); i++){
    int temp = f(amount - coins[i], i, mem);
    sum += temp;
    mem[amount][i] = temp; 
  }

  return sum;
}



int main(){

  cin >> n;
  vector <vector <int>> mem(n + 1, vector <int> (coins.size() + 1, -1)); // -1 = ยังไม่มี

  int x = f(n,0,mem);

  cout << x;  

  return 0;
}