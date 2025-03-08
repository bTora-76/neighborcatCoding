#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int rowMax, colMax;

int main(){


  
  cin >> rowMax >> colMax;


  vector<string> v;

  int sum = 0;

  for (int i = 0; i < rowMax; i++){
    string temp;
    cin >> temp;
    v.push_back(temp);
  }

  queue<pair<int, int>> q;

  for (int i = 0; i < rowMax; i++){
    for (int j = 0; j < colMax; j++){
      if (v[i][j] == '1'){
        ++sum;
        v[i][j] = '0';
        q.push({i, j});
        while (!q.empty()){
          int row = q.front().first;
          int col = q.front().second;

          q.pop();

          

          if (row-1 >= 0 &&  v[row-1][col] == '1'){
            v[row-1][col] = '0';
            q.push({row - 1, col});
          }

          if (row - 1>= 0 && col + 1 < colMax && v[row-1][col + 1] == '1'){
            v[row-1][col+1] = '0';
            q.push({row - 1, col + 1});
          }

          if (col + 1 < colMax && v[row][col+1] == '1'){
            v[row][col+1] = '0';
            q.push({row, col+1});
          }

          if (row + 1 < rowMax && col + 1 < colMax && v[row+1][col+1] == '1'){
            v[row+1][col+1] = '0';
            q.push({row +1, col+1});
          }

          if (row + 1 < rowMax && v[row+1][col] == '1'){
            v[row+1][col] = '0';
            q.push({row + 1, col});
          }

          if (row + 1 < rowMax && col - 1 >= 0 && v[row+1][col-1] == '1'){
            v[row+1][col-1] = '0';
            q.push({row + 1, col-1});
          }

          if (col - 1>= 0 && v[row][col-1] == '1'){
            v[row][col-1] = '0';
            q.push({row , col - 1});
          }

          if (row - 1 >= 0 && col - 1 >= 0 && v[row-1][col - 1] == '1'){
            v[row-1][col] = '0';
            q.push({row - 1, col - 1});
          }

          // turn to 0
          

          // check before move

          
        }
      }
    }
  }
  
  cout << sum;
  return 0;
}