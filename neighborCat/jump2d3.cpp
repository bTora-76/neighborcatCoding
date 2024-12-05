#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mp;

int f(int row, int col){
  if(row == 0 && col == 0)return 0;
  if (row < 0 || col < 0)return 20000;
  if (mp[row][col] == '#')return 20000;

  //general case
  return 1 + min(f(row - 3, col), min(f(row - 5, col), min(f(row - 9, col), min(f(row, col - 4), f(row, col - 9)))));
}

int main(){
  // get map

  int row, col;
  cin >> row >> col;

  for (int i = 0; i <= row; i++){
    string temp;
    getline(cin, temp);
    mp.push_back(temp);
  }




  cout << f(row,col);

  return 0;

}