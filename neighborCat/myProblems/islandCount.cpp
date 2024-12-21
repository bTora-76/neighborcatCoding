#include <iostream>
#include <vector>
using namespace std;

int rowMax, colMax;

int mp[100][100];
// bool check[100][100];

int count = 0;

void f(int row, int col){
    //base case
    if (row < 0 || col < 0 || row >= rowMax || col >= colMax)return; //border
    if (mp[row][col] == 0) return;

    // general case


    // for (int i = 0; i < rowMax; i++){
    //     for (int j = 0; j < colMax; j++){
    //         cout << mp[i][j];
    // }
    // cout << '\n';
    // }
    // cout << count << '\n';

    // system("pause");

    mp[row][col] = 0;

    f(row + 1, col);
    f(row - 1, col);
    f(row , col + 1);
    f(row , col - 1);
        
};


int main(){
    cin >> rowMax >>colMax;
    
    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            cin >> mp[i][j];
    }
    }

    // for (int i = 0; i < rowMax; i++){
    //     for (int j = 0; j < colMax; j++){
    //         cout << mp[i][j];
    // }
    // cout << '\n';
    // }

    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if (mp[i][j] == 1){
                
                ++count;
                cout << count << '\n'; 
                f(i, j);

                for (int i = 0; i < rowMax; i++){
                    for (int j = 0; j < colMax; j++){
                        cout << mp[i][j];
                    }
                    cout << '\n';
                }
            }
            
        }
    }

        cout << count;
}
