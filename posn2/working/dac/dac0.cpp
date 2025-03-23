#include <iostream>
#include <vector>
using namespace std;


// find mod of large numbers

//formula: x^n = 1; n = 0, x^(n/2) * x^(n/2); n is even, x^(n-1) * x; n is odd

long long DAC(long long a, long long b, long long m){

  if(b == 0) return 1;

  if(b%2 == 0){

    return (DAC(a,b/2,m) * DAC(a,b/2,m)) % m;
  }

  if(b%2 == 1){
    return (a * DAC(a,b-1,m)) %m;
  }                     

  return 0;
}

int main(){

    long long a, b, m;
    cin >> a >> b >> m;

    cout << DAC(a,b,m);



    return 0;
}