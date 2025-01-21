#include <iostream>
#include <vector>
#include <string>
using namespace std;




int main(){

  int size1;     //, size2;
  cin >> size1 ; // >> size2;
  cin.ignore(); // getline is getting the \n from enter causing it to only read 2 strings
  int size2;
  cin >> size2;
  cin.ignore();

  // vector<string> input1(3);
  // vector<string> input2(3);

  bool arr1[3][1000];
  bool arr2[3][1000];

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 1000; j++){
      arr1[i][j] = false;
      arr2[i][j] = false;
    }
  }

    // get input of num1

    for (int i = 0; i < 3; i++)
    {
      string temp;
      getline(cin, temp);

      // fill bool arr
      for (int j = 0; j < temp.size(); j++)
      {
        if (temp[j] != ' ')
          arr1[i][j] = true;
      }
    }

    for (int i = 0; i < 3; i++)
    {
      string temp;
      
      getline(cin, temp);

      // fill bool arr
      for (int j = 0; j < temp.size(); j++)
      {
        if (temp[j] != ' ')
          arr2[i][j] = true;
      }
    }

  // get input of num2



  // loop num1
  // loop แบบทีละเลข

    // จะได้skip ได้

    string num1 = "";
    string num2 = "";

    for (int k = 0; k + 2 < (size1 * 3) + size1 - 1; k += 4){
      // 8
      if (arr1[0][k+1] && arr1[1][k] && arr1[1][k+1]  && arr1[1][k+2]  && arr1[2][k] && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("8");
      // 0
      else if (arr1[0][k+1] && arr1[1][k]  && arr1[1][k+2]  && arr1[2][k] && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("0");
      // 9
      else if (arr1[0][k+1] && arr1[1][k] && arr1[1][k+1]  && arr1[1][k+2]  && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("9");
      //6
      else if (arr1[0][k+1] && arr1[1][k] && arr1[1][k+1]  && arr1[2][k] && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("6");
      //5
      else if (arr1[0][k+1] && arr1[1][k] && arr1[1][k+1] && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("5");
      // 3
      else if (arr1[0][k+1] && arr1[1][k+1]  && arr1[1][k+2] && arr1[2][k + 1] && arr1[2][k + 2])
        num1.append("3");
      //7
      else if (arr1[0][k+1] && arr1[1][k+2] && arr1[2][k + 2])
        num1.append("7");
      //4
      else if ( arr1[1][k] && arr1[1][k+1]  && arr1[1][k+2] && arr1[2][k + 2])
        num1.append("4");
      
      //2
      else if (arr1[0][k+1] && arr1[1][k+1]  && arr1[1][k+2]  && arr1[2][k] && arr1[2][k + 1])
        num1.append("2");
      // 1
      else if (arr1[1][k+2] && arr1[2][k+2])
        num1.append("1");
        }

    // cout << "Pass 1";

        for (int k = 0; k + 2 < (size2 * 3) + size2 - 1; k += 4)
        {
          // 8
          if (arr2[0][k + 1] && arr2[1][k] && arr2[1][k + 1] && arr2[1][k + 2] && arr2[2][k] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("8");
          // 0
          else if (arr2[0][k + 1] && arr2[1][k] && arr2[1][k + 2] && arr2[2][k] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("0");
          // 9
          else if (arr2[0][k + 1] && arr2[1][k] && arr2[1][k + 1] && arr2[1][k + 2] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("9");
          // 6
          else if (arr2[0][k + 1] && arr2[1][k] && arr2[1][k + 1] && arr2[2][k] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("6");
          // 5
          else if (arr2[0][k + 1] && arr2[1][k] && arr2[1][k + 1] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("5");
          // 3
          else if (arr2[0][k + 1] && arr2[1][k + 1] && arr2[1][k + 2] && arr2[2][k + 1] && arr2[2][k + 2])
            num2.append("3");
          // 7
          else if (arr2[0][k + 1] && arr2[1][k + 2] && arr2[2][k + 2])
            num2.append("7");
          // 4
          else if (arr2[1][k] && arr2[1][k + 1] && arr2[1][k + 2] && arr2[2][k + 2])
            num2.append("4");
          // 2
          else if (arr2[0][k + 1] && arr2[1][k + 1] && arr2[1][k + 2] && arr2[2][k] && arr2[2][k + 1])
            num2.append("2");
          else if (arr2[1][k + 2] && arr2[2][k + 2])
            num2.append("1");
        }

        // cout << "Pass 2";


      

      // check output
      // for (int i = 0; i < 3; i++){
      //   for (int j = 0; j < (size1 * 3) + size1 - 1; j++){
      //     cout << arr1[i][j];
      //   }
      //   cout << '\n';
      // }

        cout << stoll(num1) + stoll(num2);

        return 0;
}
