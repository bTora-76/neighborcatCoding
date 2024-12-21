#include <iostream>
#include <vector>
using namespace std;

vector<int> coins = {1,2,5};
int n;

int f(int amount){
  if(amount == 0)
    return 0;
  if (amount < 0)
    return 12000;

  int minVal = 12000;
  for (int i = 0; i < coins.size(); i++){
    minVal = min(minVal, f(amount - coins[i]));
  }

  return 1 + minVal;
}



int main(){
 
  cin >> n;
  int x = f(n);

  if (x >= 12000){
    cout << "-1";
  }
  else{
    cout << x;
  }

  return 0;
}