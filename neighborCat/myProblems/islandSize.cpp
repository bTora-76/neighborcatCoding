// find max area of biggest island

#include <iostream>
#include <vector>
using namespace std;

int rowMax, colMax;
int maxSize = 0;
int mp[100][100];
// bool check[100][100];

int f(int row, int col, int size){
    //base case
    if (row < 0 || col < 0 || row >= rowMax || col >= colMax)return 0; //border
    if (mp[row][col] == 0) return 0;

    mp[row][col] = 0;

    return 1 + f(row + 1, col, size + 1) + f(row - 1, col, size + 1) + f(row , col + 1, size + 1) + f(row , col - 1, size + 1);        
};


int main(){
    cin >> rowMax >>colMax;
    
    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            cin >> mp[i][j];
    }
    }

    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if (mp[i][j] == 1){
                int temp = f(i, j,0);
                if (temp > maxSize){
                    maxSize = temp;
                }
            }
            
        }
    }

    cout << maxSize;
    return 0;
}
