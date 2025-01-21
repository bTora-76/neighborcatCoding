#include <iostream>
#include <vector>
using namespace std;

int main(){

  int ans[5] = {0};

  int d;
  cin >> d;

  int ones = 1;
  int tens = 0;
  int hundreds = 0;

  for (int i = 1; i <= d; i++){
    // cout << i << " " << hundreds << tens << ones << '\n';
    // one digit
    if (ones >= 1 && ones <= 3){
      ans[0] += ones;
    }
    else if (ones == 4){
      ans[0] += 1;
      ans[1] += 1;
    }
    else if (ones >= 5 && ones <= 8){
      ans[0] += (ones - 5);
      ans[1] += 1;
    }
    else if (ones == 9){
      ans[2] += 1;
      ans[0] += 1;
    }

    // two digit

    if (tens <= 3 && tens >= 1){
      ans[2] += tens;
    }
    else if (tens == 4){
      ans[2] += 1;
      ans[3] += 1;
    }
    else if (tens >= 5 && tens <= 8){
      ans[3] += 1;
      ans[2] += (tens - 5);
    }

    else if (tens == 9){
      ans[2] += 1;
      ans[4] += 1;
    }

    // three digits

    if (hundreds >= 1 && hundreds <= 3){
      ans[4] += hundreds;
    }


    
    // manage unit
    if (tens == 9 && ones == 9){
      ones = 0;
      tens = 0;
      hundreds += 1;
    }

    else if (ones == 9){
      ones = 0;
      tens += 1;
    }
    
    else{
      ++ones;
    }
  }

  for (int e: ans){
    cout << e << " ";
  }

  return 0;
}