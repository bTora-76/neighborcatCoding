#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited [5][5];
double inputs[5][5];
int maxRow, maxCol;

double f(int row, int col){
    // เดินก่อน check
    if (row > maxRow || col > maxCol || row == 0 || col == 0 || visited[row][col] == true )return 1e9;
    
    double minVal = inputs[row][col];
    if (visited[row][col] != true){
    
    visited[row][col] = true;
    
    if (visited[row - 1][col] == false){
        inputs[row - 1][col] += 0.1 * inputs[row][col];
    }
    if (visited[row - 1][col+1] == false){
        inputs[row - 1][col + 1] += 0.1 * inputs[row][col];
    }
    if (visited[row][col+1] == false){
        inputs[row][col+1] += 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col + 1] == false){
        inputs[row + 1][col + 1] += 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col] == false){
        inputs[row + 1][col] += 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col - 1] == false){
        inputs[row + 1][col - 1] += 0.1 * inputs[row][col];
    }
    if (visited[row][col-1] == false){
        inputs[row ][col-1] += 0.1 * inputs[row][col];
    }
    if (visited[row - 1][col-1] == false){
        inputs[row - 1][col-1] += 0.1 * inputs[row][col];
    }

    minVal += min({f(row-1,col), f(row-1,col+1), f(row, col+1), f(row+1, col+1), f(row + 1, col), f(row+1,col-1), f(row,col-1), f(row-1,col-1)});

    if (visited[row - 1][col] == false){
        inputs[row - 1][col] -= 0.1 * inputs[row][col];
    }
    if (visited[row - 1][col+1] == false){
        inputs[row - 1][col + 1] -= 0.1 * inputs[row][col];
    }
    if (visited[row][col+1] == false){
        inputs[row][col+1] -= 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col + 1] == false){
        inputs[row + 1][col + 1] -= 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col] == false){
        inputs[row + 1][col] -= 0.1 * inputs[row][col];
    }
    if (visited[row + 1][col - 1] == false){
        inputs[row + 1][col - 1] -= 0.1 * inputs[row][col];
    }
    if (visited[row][col-1] == false){
        inputs[row ][col-1] -= 0.1 * inputs[row][col];
    }
    if (visited[row - 1][col-1] == false){
        inputs[row - 1][col-1] -= 0.1 * inputs[row][col];
    }

    // inputs[row - 1][col] -= 0.1 * inputs[row][col];
    // inputs[row - 1][col + 1] -= 0.1 * inputs[row][col];
    // inputs[row][col+1] -= 0.1 * inputs[row][col];
    // inputs[row + 1][col + 1] -= 0.1 * inputs[row][col];
    // inputs[row + 1][col] -= 0.1 * inputs[row][col];
    // inputs[row+1][col-1] -= 0.1 * inputs[row][col];
    // inputs[row][col-1] -= 0.1 * inputs[row][col];
    // inputs[row-1][col-1] -= 0.1 * inputs[row][col];

    visited[row][col] = false;
        
    }
    

    return minVal;

}

int main(){

    // set visited
    for (int i = 0; i <= 4; i++){
        for (int j = 0; j <= 4; j++){
            if(i == 0 || j == 0 || i == 4 || j == 4) visited[i][j] = true;
            else {visited[i][j] = false;}
        }
    }

    //set inputs
    for (int i = 0; i <= 4; i++){
        for (int j = 0; j <= 4; j++){
            inputs[i][j] = 0;
        }
    }

    
    cin >> maxRow >> maxCol;

    for (int i = 1; i <= maxRow; i++){
        for (int j = 1; j <= maxCol; j++){
            cin >> inputs[i][j];
            visited[i][j] = false;
        }
    }

    // for (int i = 0; i < maxRow; i++){
    //     for (int j = 0; j < maxCol; j++){
    //         cout << inputs[i][j];
    //     }
    // }

    double minSum = 999999;

    // loop starting points
    for (int i = 1; i <= maxRow; i++){
        for (int j = 1; j <= maxCol; j++){
            minSum = min(minSum, f(i, j));
        }

    }

    cout << minSum;

    return 0;
}