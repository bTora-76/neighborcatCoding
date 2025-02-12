#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rowMax, colMax;

vector<vector<bool>> v(2001, vector <bool> (2001,false));

void f(int row, int col ){

  // เดินแล้ว check

  //basecase

  if (v[row][col] == false)
    return;

  // if current element isn't 0

  v[row][col] = false;

  if (row-1 >= 0 &&  v[row-1][col] == true){
    f(row-1,col);
  }

  if (row - 1>= 0 && col + 1 < colMax && v[row-1][col + 1] == true){
    f(row - 1, col + 1);
  }

  if (col + 1 < colMax && v[row][col+1] == true){
      f(row, col + 1);
  }

  if (row + 1 < rowMax && col + 1 < colMax && v[row+1][col+1] == true){
    f(row + 1, col + 1);
  }

  if (row + 1 < rowMax && v[row+1][col] == true){
    f(row + 1, col);
  }

  if (row + 1 < rowMax && col - 1 >= 0 && v[row+1][col-1] == true){
    f(row + 1, col - 1);
  }

  if (col - 1>= 0 && v[row][col-1] == true){
    f(row, col - 1);
  }

  if (row - 1 >= 0 && col - 1 >= 0 && v[row-1][col - 1] == true){
    f(row - 1, col - 1);
  }

}

int main(){


  
  cin >> rowMax >> colMax;

  int sum = 0;

  for (int i = 0; i < rowMax; i++){
    string temp;
    cin >> temp;
    for (int j = 0; j < colMax;j++){
      if(temp[j] == '1'){
        v[i][j] = true;
      }
    }
  }


  for (int i = 0; i < rowMax; i++){
    for (int j = 0; j < colMax; j++){
      if (v[i][j] == true){
        ++sum;
        f(i, j);
      }
    }
  }
  
  cout << sum;
  return 0;
}