#include <iostream>
using namespace std;

int arr[1001][1001];

int main(){

    int n,k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
          arr[i][j] = 0;
        }
    }

    // get input
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        // string index starts from 0
        for (int j = 0; j < n; j++){
            if(s[j] == '*'){
                arr[i][j + 1] = 1;
            } 
            
        }
    }

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= n; j++){
    //       cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    //   }

    //   return 0;

    // preprocess

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
          arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        cout << arr[i][j] << " ";
      }
      cout << '\n';
    }

    // querries

    // for (int i = 0; i < k; i++){
    //     int y1, x1, y2, x2;
    //     cin >> y1 >> x1 >> y2 >> x2;
    //     // --x1; --y1; --x2; --y2; // account for problems that use -base 1 indexing
    //     cout << arr[y2][x2] - arr[y1 - 1][x2] - arr[y2][x1 - 1] + arr[y1 - 1][x1 - 1] << '\n';
    // }



    return 0;
}