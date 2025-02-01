#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



// int DAC(vector<int> &v, int L, int R, int key){
//   //base case

//   // not found
//   if(L > R){
//     return -1;
//   }
  

  
//   int mid = L + ((R - L) / 2);

//   // mid must be checked first!
//   if(key == v[mid]){
//     return mid;
//   }

//   // check right
//   if (key > v[mid]){
//     return DAC(v, mid + 1, R, key);
//   }
//   else{
//     return DAC(v, L, mid-1, key);
//   }
// }

int main(){
  vector<int> v = {10,15,20,30,50,60};
  
  auto it = upper_bound(v.begin(), v.end(), 20);

  if (it != v.end()){
    cout << it - v.begin() << '\n';
    cout << *it;
  }

  else {
    cout << "ELEMENT NOT FOUND";
  }

  return 0;
}