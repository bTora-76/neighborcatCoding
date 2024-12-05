#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> mp;

int c,r;

int f(int row, int col){
  // basecase
  if (row >= r || col >= c)return 0;
  // return เป็น 0 ได้เพราะหาค่า max
  if (mp[row][col] == '#')return 0;

  // general case
  // ถ้าเป็น o จะ +1 และทำต่อไป แต่ถึงไม่ใช่ o ก็ต้องทำต่อไปอยู่ดี เพื่อ maintain ค่า max
  if (mp[row][col] == 'o') return 1 + max(f(row+1,col), f(row,col +1));
  else
    return max(f(row + 1, col), f(row, col + 1));
}

int main(){

  cin >> c >> r;
  cin.ignore();

  for (int i = 0; i < r; i++)
  {
    string temp;
    getline(cin, temp);
    mp.push_back(temp);
  }

  cout << f(0, 0);
  return 0;
}