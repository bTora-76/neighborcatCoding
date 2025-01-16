#include <iostream>
#include <vector>
using namespace std;



int main() {
  char ans[10][80];

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 80; j++){
      ans[i][j] = '.';
    }
  }

  int start, height;

  cin >> start >> height;
  int maxheight = 10;

  int layer = 0;
  bool isStart, isEnd;

  for (int i = maxheight - height; i < maxheight; i++){
    isStart = isEnd = false;

    for (int j = start - 1; j <= start - 1 + (height*2); j++){
      if (j == height - 1 - layer + start - 1){
        ans[i][j] = '/';
        isStart = true;
      }
      else if (j == height + layer + start - 1){
        ans[i][j] = '\\';
        isEnd = true;
      }

      else if (isStart == true && isEnd == false){
        ans[i][j] = 'x';
      }

    }
    ++layer;
  } 



  //output

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 80; j++){
      cout << ans[i][j];
    }
    cout << '\n';
  }

  return 0;
}