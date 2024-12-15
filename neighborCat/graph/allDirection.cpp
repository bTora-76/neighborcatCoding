//flood fill and backtracking
// เดินกลับมาเหยียบอันเดิมไม่ได้ = flood fill
// ถ้าเหยียบได้ใช้ backtracking

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> mp;


int c,r;

void showPath(int row, int col, vector <vector<int>> &check){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      cout << check[i][j] << " ";
    }
    cout << '\n';
  }
}

int f(int row, int col, vector <vector<int>> &check){
  // basecase
  if(row == r-1 && col == c-1) return 0;
  showPath(row,col);
  if (row >= r || col >= c)return 2000;
  if(row < 0 || col < 0)return 2000;
  // ป้องกันการเดินซ้ำช่องที่เดินไปแล้ว
  if(check[row][col] == true) return 2000;
  
  // return เป็น 0 ได้เพราะหาค่า max
  if (mp[row][col] == '#')return 2000;
 
  check[row][col] = true;
  // general case เป็นจุดแน่นอน
  int x = 1 + (min(f(row, col + 1, check),min( f(row + 1, col, check),min(f(row - 1, col, check), f(row, col - 1, check)))));
  // ทำให้มันเป้น false จะได้ backtracking ได้
  check[row][col] = false;
  return x;
}

int main(){
  

  cin >> r >> c;
  vector <vector <int>> check(r, vector<int> (c,-1));

  for (int i = 0; i < r; i++)
  {
    string temp;
    cin >> temp;
    mp.push_back(temp);
  }

  cout << f(0, 0, check) << '\n';
  
  return 0;


}