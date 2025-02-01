#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

bool comp(vector<int> & v1, vector <int> &v2){

  // if the index 0 is equal
  if(v1[0] == v2[0]){
    return v1.back() > v2.back();
  }


  return v1[0] < v2[0];
}


int main(){

  int row, col;
  cin >> row >> col;

  vector<vector<int>> v(row, vector<int>(col));

    for (int i = 0; i < row; i++){
      for (int j = 0; j < col; j++){
        cin >> v[i][j];
      }
  }

    // // get input as whol number
    // for (int i = 0; i < row; i++){
    //   int num = 0;
    //   for (int j = col - 1; j >= 0; j--){
    //     int temp;
    //     cin >> temp;
    //     num += (temp * pow(10, j));
    //   }

    // }

    // sorting

    // sort all so that it sorts first index
    sort(v.begin(), v.end(), comp); 

  //sort 2nd to col -1 index

  // for (int i = 0; i < row - 1; i++){
  //   for (int j = 0; j < row - i - 1; j++){
  //     if(v[j]/100 == v[j+1]/100 && v[j] - ((v[j]/100) * 100)  <  v[j+1] - ((v[j+1]/100) *100)){
  //       int temp = v[j];
  //       v[j] = v[j + 1];
  //       v[j + 1] = temp;
  //     }
  //   }
  // }

    cout << '\n';

  // for (int i = 0; i < row; i++){
  //   string output = to_string(v[i]);
  //   for (int j = 0; j < col; j++){
      
  //     cout << output[j] << " ";
  //   }
  //   cout << '\n';
  // }

  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      cout << v[i][j] << " ";
    }
    cout << '\n';
  }

      return 0;
}