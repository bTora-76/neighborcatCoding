#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;

  int inputs[10][5];


  // get input
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      cin >> inputs[i][j];
    }
  }

  // for (int i = 0; i < n; i++){
  //   for (int j = 0; j < 5; j++){
  //     cout << inputs[i][j] << " ";
  //   }
  //   cout << '\n';
  // }

  int lbs = 0;
  int remainder[5] = {0, 0, 0, 0, 0};
  int totalCol[5] = {0, 0, 0, 0, 0};
  // process

  // find total of each row
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      totalCol[j] += inputs[i][j];
    }
  }

  // first col
  lbs += totalCol[0];

  //second col
  lbs += totalCol[1];
  remainder[1] += totalCol[1];

  // third col
    if (totalCol[2] % 2 == 0){
      // no remainder 100%
      int maxEven = totalCol[2] / 2;
      lbs += maxEven;
    }
  
    else if (totalCol[2] % 2 == 1){
      int maxEven = totalCol[2] / 2;
      lbs += maxEven;
      lbs += 1;
      // divide the extra 2/4 into two 1/4 cuz we know we don't need 2/4 no more, we only need ones that are smaller
      remainder[1] += 2;
    }

    // forth col
    // clear the remainders
    while(totalCol[3] > 0 && remainder[1] > 0){
      --remainder[1];
      --totalCol[3];

      
    }
    // add the whole ones
    while (totalCol[3] >= 4){
      ++lbs;
      totalCol[3] -= 4;
    }

    // if totalCol[3] still >0 but < 4

    if (totalCol[3] > 0 && totalCol[3] < 4){
      ++lbs;
      remainder[1] += (4 - totalCol[3]);
    }

    // col 4
    // convert 1/4 to 1/8
    remainder[0] += 2 * remainder[1];

    // clear the remainders
    while(totalCol[4] > 0 && remainder[0] > 0){
      --remainder[0];
      --totalCol[4];
    }

    // add the whole ones
    while (totalCol[4] >= 8){
      ++lbs;
      totalCol[4] -= 8;
    }

    // if totalCol[4] still >0 but < 8

    if (totalCol[4] > 0 && totalCol[4] < 8){
      ++lbs;
      remainder[1] += (8 - totalCol[4]);
    }





    // for (int i : totalCol)
    // {
    //   cout << i << " ";
    // }

    cout << lbs;
    return 0;
}