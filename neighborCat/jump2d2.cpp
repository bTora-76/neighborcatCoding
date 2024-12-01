#include <iostream>
#include <string>
#include <vector>
using namespace std;


int f(int row, int col, vector <string> &mp){

    if (row == 0 && col == 0)return 1;
    if (row < 0 || col < 0) return 0;   

    if (mp[row][col] == '#') return 0;



    return f(row -3, col, mp) + f(row -5, col,mp) + f(row -9, col,mp) + f (row, col-4,mp) + f (row, col-9,mp);

}

int main(){
    int row, col;
    vector <string> mp;
    cin >> row >>  col;

    for (int i = 0; i <= row; i++){
        string temp;
        getline(cin,temp);
        mp.push_back(temp);

    }

    cout << f(row, col, mp);

    return 0;
}