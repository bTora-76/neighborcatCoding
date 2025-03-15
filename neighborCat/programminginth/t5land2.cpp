#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int maxRow, maxCol;
double arr[5][5]; // global automantically sets to 0 even in 2d
bool visited[5][5];

double f(int buys){
    if (buys == 0) return 0;

    double minVal = 1e9;

    for (int i = 1; i <= maxRow; i++){
        for (int j = 1; j <= maxCol; j++){
           if(visited[i][j] != true){
            visited[i][j] = true;
            arr[i - 1][j] += 0.1 * arr[i][j];
            arr[i - 1][j + 1] += 0.1 * arr[i][j];
            arr[i][j+1] += 0.1 * arr[i][j];
            arr[i + 1][j + 1] += 0.1 * arr[i][j];
            arr[i + 1][j] += 0.1 * arr[i][j];
            arr[i + 1][j - 1] += 0.1 * arr[i][j];
            arr[i ][j-1] += 0.1 * arr[i][j];
            arr[i - 1][j-1] += 0.1 * arr[i][j];

            minVal = min(minVal, arr[i][j] + f(buys-1));  
            
            arr[i - 1][j] -= 0.1 * arr[i][j];
            arr[i - 1][j + 1] -= 0.1 * arr[i][j];
            arr[i][j+1] -= 0.1 * arr[i][j];
            arr[i + 1][j + 1] -= 0.1 * arr[i][j];
            arr[i + 1][j] -= 0.1 * arr[i][j];
            arr[i + 1][j - 1] -= 0.1 * arr[i][j];
            arr[i ][j-1] -= 0.1 * arr[i][j];
            arr[i - 1][j-1] -= 0.1 * arr[i][j];
            
            visited[i][j] = false;  
           }
        }
    }

    return minVal;
}

int main(){
    cin >> maxRow >> maxCol;
    for (int i = 1; i <= maxRow; i++){
        for (int j = 1; j <= maxCol; j++){
            cin >> arr[i][j];
        }
    }
    cout << fixed << setprecision(2) << f(maxRow * maxCol);


}