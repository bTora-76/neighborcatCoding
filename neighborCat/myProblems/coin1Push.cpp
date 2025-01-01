//dp

#include <iostream>
#include <vector>
using namespace std;

vector<int> coins = {1,2,5};




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