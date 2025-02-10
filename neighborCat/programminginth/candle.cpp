#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rowMax, colMax;


void f(int row, int col, vector <vector <char>> &v){

  // เดินแล้ว check

  //basecase

  if (row == rowMax || col == colMax || row < 0 || col < 0)
    return;

  if (v[row][col] == '0')
    return;

  // if current element isn't 0

  v[row][col] = '0';

  f(row-1,col,v);
  f(row - 1, col + 1, v);
  f(row, col + 1, v);
  f(row + 1, col + 1, v);
  f(row + 1, col, v);
  f(row + 1, col - 1, v);
  f(row, col - 1, v);
  f(row - 1, col - 1, v);
}

int main(){


  
  cin >> rowMax >> colMax;

  
  vector<vector <char>> v(rowMax, vector<char>(colMax));

  int sum = 0;

  for (int i = 0; i < rowMax; i++){
    string temp;
    cin >> temp;
    for (int j = 0; j < colMax;j++){
      v[i][j] = temp[j];
    }
  }


  for (int i = 0; i < rowMax; i++){
    for (int j = 0; j < colMax; j++){
      if (v[i][j] == '1'){
        ++sum;
        f(i, j, v);
      }
    }
  }
  
  cout << sum;
  return 0;
}