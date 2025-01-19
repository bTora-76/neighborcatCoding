#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int main() {
  
  int n;
  cin >> n;

  priority_queue<pair<int,int>, vector <pair<int,int>>, greater<pair<int,int>>> inputs; // data of input commands {s, h} (this is array)
  priority_queue<pair<int,int>> tempInputs;


  // get input + findmax height
  int maxHeight = 0;

  for (int i = 0; i <n; i++){
    pair<int, int> temp;
    cin >> temp.first >> temp.second;
    inputs.push(temp);
    tempInputs.push(temp);
    
  }

  //find max height 
  while (!tempInputs.empty()){
    maxHeight = max(maxHeight, tempInputs.top().second);
    tempInputs.pop();
  }
  // loop to check every pair

  // ทำแบบนี้ไม่ต้องใช้ condition yuanๆ


  

  

  // fill ans arr
  char ans[maxHeight][100];

  for (int i = 0; i < maxHeight; i++){
    for (int j = 0; j < 100; j++){
      ans[i][j] = '.';
    }
  }

  // draw
  int lastStart, lastHeight = 0;
  

  // 1 outer loop = 1 mountain
  for (int k = 0; k < n; k++){
    int layer = 0;
    int start = inputs.top().first;
    int height = inputs.top().second;
    

    for (int i = maxHeight - height; i < maxHeight; i++){
      for (int j = start - 1; j <= start - 1 + (height*2); j++){

        if (ans[i][j] == '\\' && j == height - 1 - layer + (start - 1)){
          ans[i][j] = 'v';
        }

        // left of mid
        else if  (j == height - 1 - layer + (start - 1) && ans[i][j] != 'X'){
          ans[i][j] = '/';
        }
        // right of mid
        else if (j == height + layer + (start - 1) && ans[i][j] != 'X'){
          ans[i][j] = '\\';
        }

        // this will override any border

        if (j > height - 1 - layer + start - 1 && j < height + layer + start - 1){
          ans[i][j] = 'X';
        }

      }
      ++layer;
    }
    

    // find max space for x
    if (k == n-1){
      lastStart = start;
      lastHeight = height;
    }

    inputs.pop();
  }

  
  for (int i = 0; i < maxHeight; i++){
    for (int j = 0; j < lastStart + (2 * lastHeight) - 1 ; j++){
      cout << ans[i][j];
    }
    cout << '\n';
  } 

  

  return 0;
}