#include <iostream>
using namespace std;

int main(){

  int n;
  cin >> n;

  int inputs[n];

  for (int i = 0; i < n; i++){
    cin >> inputs[i];
  }

  //process

  int arr[n + 1];
  arr[0] = 0;

  for (int i = 1; i <= n; i++){
    arr[i] = arr[i - 1] + inputs[i - 1];
  }


  int k;
  cin >> k;

  int a, b;

  for (int i = 0; i < k; i++){
    cin >> a >> b;
    cout << arr[b] - arr[a - 1] << '\n';
  }
  
}