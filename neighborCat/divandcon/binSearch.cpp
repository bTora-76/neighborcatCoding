#include <iostream>
#include <vector>
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
  vector<int> v = {30, 40, 75, 20};
  
  // cout << DAC(v, 0, v.size() - 1, 100);
  int key = 75;
  int L = 0;
  int R = v.size() - 1;
  int mid;

  // loop 1 ครั้ง = divide 1 รอบ
  while (L <= R){
    mid = L + ((R - L) / 2);

    if (key == v[mid]) break;

    if(key < v[mid]){
      R = mid - 1;
    }
    else if (key > v[mid]){
      L = mid + 1;
    }
  }

  cout << mid;
  return 0;
}