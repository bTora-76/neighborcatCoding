  #include <iostream>
  using namespace std;

  int arr[1000][1000];





  int main(){
    int maxRow, maxCol;
    cin >> maxRow >> maxCol;

    // includes padding
    for (int i = 0; i <= maxRow; i++){
      for (int j = 0; j <= maxCol; j++){
        arr[i][j] = 0;
      }
    }


    // inputs

    for (int i = 1; i <= maxRow; i++){
      for (int j = 1; j <= maxCol; j++){
        cin >> arr[i][j];
      }
    }



    // preprocess >> uses the input array to change value

    for (int i = 1; i <= maxRow; i++){
      for (int j = 1; j <= maxCol; j++){
        arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
      }
    }

    // output the preprocessed

    // for (int i = 1; i <= maxRow; i++){
    //   for (int j = 1; j <= maxCol; j++){
    //     cout << arr[i][j] << " ";
    //   }
    //   cout << '\n';
    // }

    // query

    int query;
    cin >> query;

    for (int i = 0; i < query; i++){
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      // --x1; --y1; --x2; --y2; // account for problems that use -base 1 indexing
      cout << arr[y2][x2] - arr[y1 - 1][x2] - arr[y2][x1 - 1] + arr[y1 - 1][x1 - 1] << '\n';
    }


    return 0;
  }