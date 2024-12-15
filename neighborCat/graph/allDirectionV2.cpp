//  use void function

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
  // system("pause");
}

void f(int row, int col, vector <vector<int>> &check){
  // basecase
  cout << row << col << '\n';

  showPath(r,c,check);
  system("pause");
  
  if(col + 1 < c && mp[row][col+1] != '#' && (check[row][col+1] == -1  || check[row][col] + 1 < check[row][col+1])){
    // set the next square to this square + 1
    check[row][col+1] = check[row][col] + 1; 
    f(row,col+1,check);
  }

  if(row + 1 < r && mp[row+1][col] != '#' && (check[row+1][col] == -1 || check[row][col] + 1 < check[row+1][col])){
    // set the next square to this square + 1
    check[row+1][col] = check[row][col] + 1; 
    f(row+1,col,check);
  }

  if(row - 1 >= 0 && mp[row-1][col] != '#' && (check[row-1][col] == -1 || check[row][col] + 1 < check[row-1][col])){
    // set the next square to this square + 1
    check[row-1][col] = check[row][col] + 1; 
    f(row-1,col,check);
  }

  if(col - 1 >= 0 && mp[row][col-1] != '#' && (check[row][col-1] == -1 || check[row][col] + 1 < check[row][col-1])){
    // set the next square to this square + 1
    check[row][col-1] = check[row][col] + 1; 
    f(row,col-1,check);
  }

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

  check[0][0] = 0;
  f(0,0,check);
  showPath(r,c,check);
  
  return 0;


}