#include <iostream>
#include <vector>
using namespace std;

int DAC(vector<int> &v, int L, int R){
  //base case
  if(L == R){
    return v[L];
  }

  
  int mid = L + ((R - L) / 2);
  int sub1 = DAC(v, L, mid);
  int sub2 = DAC(v, mid + 1, R);
  int biggerSol = sub1 + sub2;

  return biggerSol;
}

int main(){
  vector<int> v = {30, 40, 75, 20};
  cout << DAC(v, 0, v.size() - 1);
}