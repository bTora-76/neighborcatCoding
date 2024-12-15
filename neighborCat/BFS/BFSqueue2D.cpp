#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int row, col;

vector <string> mp;
vector <vector <int>> visited(100, vector <int> (100, 0));

queue<pair<int,int>> myqueue;

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


  myqueue.push({0,0});
  visited[0][0] = 1;


  while(!myqueue.empty()){
    int x = myqueue.front().first;
    int y = myqueue.front().second;
    cout << x << " " << y << '\n';

    myqueue.pop();
    int h = visited[x][y] + 1;

    if(x-1 >= 0 && mp[x-1][y] != '#' && (visited[x-1][y] == 0 || visited[x-1][y] > visited[x][y] + 1 )){
      myqueue.push({x-1,y});
      visited[x-1][y] = h;
    }
    if(x+1 < row && mp[x+1][y] != '#' && (visited[x+1][y] == 0 || visited[x+1][y] > visited[x][y] + 1 )){
      myqueue.push({x+1,y});
      visited[x+1][y] = h;
    }
    if(y-1 >= 0 && mp[x][y-1] != '#' && (visited[x][y-1] == 0 || visited[x][y-1] > visited[x][y] + 1 )){
      myqueue.push({x,y-1});
      visited[x][y-1] = h;
    }
    if(y+1 < col && mp[x][y+1] != '#' && (visited[x][y+1] == 0 || visited[x][y+1] > visited[x][y] + 1 )){
      myqueue.push({x,y+1});
      visited[x][y+1] = h;
    }
    showPath(row,col, visited);
    system("pause");

    
  }

 

  cout << visited[row-1][col-1];

  return 0;
}