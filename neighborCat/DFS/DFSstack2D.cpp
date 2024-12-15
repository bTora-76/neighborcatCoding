#include <iostream>
#include <vector>
#include <stack>
using namespace std;



int row, col;

vector <string> mp;
vector <vector <int>> visited(100, vector <int> (100, 0));

stack<pair<int,int>> myStack;

void showPath(int row, int col, vector <vector<int>> &check){
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      cout << check[i][j] << " ";
    }
    cout << '\n';
  }
}

int main(){
  

  cin >> row >> col;

  // input 

  for(int i = 0; i < row; i++){
    string temp;
    cin >> temp;
    mp.push_back(temp);
  }


  myStack.push({0,0});
  visited[0][0] = 1;


  while(!myStack.empty()){
    int x = myStack.top().first;
    int y = myStack.top().second;
    cout << x << " " << y << '\n';

    myStack.pop();
    int h = visited[x][y] + 1;

    if(x-1 >= 0 && mp[x-1][y] != '#' && (visited[x-1][y] == 0 || visited[x-1][y] > visited[x][y] + 1 )){
      myStack.push({x-1,y});
      visited[x-1][y] = h;
    }
    if(x+1 < row && mp[x+1][y] != '#' && (visited[x+1][y] == 0 || visited[x+1][y] > visited[x][y] + 1 )){
      myStack.push({x+1,y});
      visited[x+1][y] = h;
    }
    if(y-1 >= 0 && mp[x][y-1] != '#' && (visited[x][y-1] == 0 || visited[x][y-1] > visited[x][y] + 1 )){
      myStack.push({x,y-1});
      visited[x][y-1] = h;
    }
    if(y+1 < col && mp[x][y+1] != '#' && (visited[x][y+1] == 0 || visited[x][y+1] > visited[x][y] + 1 )){
      myStack.push({x,y+1});
      visited[x][y+1] = h;
    }
    showPath(row,col, visited);
    system("pause");

    
  }

 

  cout << visited[row-1][col-1];

  return 0;
}