#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main(){

  int row, col;
  cin >> row >> col;

  vector <int> v(row);

  // get input as whol number
  for (int i = 0; i < row; i++){
    int num = 0;
    for (int j = col - 1; j >= 0; j--){
      int temp;
      cin >> temp;
      num += (temp * pow(10, j));
    }
    v[i] = num;
  }



  //sorting

  // sort all so that it sorts first index
  sort(v.begin(), v.end()); 

  //sort 2nd to col -1 index

  for (int i = 0; i < row - 1; i++){
    for (int j = 0; j < row - i - 1; j++){
      if(v[j]/100 == v[j+1]/100 && v[j] - ((v[j]/100) * 100)  <  v[j+1] - ((v[j+1]/100) *100)){
        int temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }

    cout << '\n';

  for (int i = 0; i < row; i++){
    string output = to_string(v[i]);
    for (int j = 0; j < col; j++){
      
      cout << output[j] << " ";
    }
    cout << '\n';
  }

    return 0;
}