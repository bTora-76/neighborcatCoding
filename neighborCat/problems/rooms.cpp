#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r,c;

vector<string> mp;
int check[35][35] = {0};

vector <pair<int,int>> warps;

void getWarp(){
    for (int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(mp[i][j] == 'W') warps.push_back({i,j});
        }
    }
}

void showPath(){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cout << check[i][j];
        }
        cout << '\n';
    }
}


// need to use flood field
int f(int row, int col){

    // basecase
    
    if(row < 0 || col < 0 || row >= r || col >= c) return 0; //border

    if(check[row][col] == 1) return 0;

   
    if(mp[row][col] == '#') return 0;
    check[row][col] = 1; // check before move
    if(mp[row][col] == '*') return 1 + f(row + 1,col) + f(row -1 ,col) + f(row,col + 1) + f(row,col - 1);    

    //general choice >> if is A or ., then walk.

    // warp
    if(mp[row][col] == 'W'){
        int x = 0;
        // loop through all warp coordinates
        for (int i = 0; i < warps.size(); i++ ){
            x += f(warps[i].first + 1, warps[i].second) + f(warps[i].first - 1, warps[i].second) + f(warps[i].first, warps[i].second + 1) + f(warps[i].first, warps[i].second - 1);
        }
        return x;
    }

    return f(row + 1,col) + f(row -1 ,col) + f(row,col + 1) + f(row,col - 1);
}

int main(){
    cin >> r >> c;

    // input
    for (int i = 0; i < r; i++){
        string temp;
        cin >> temp;
        mp.push_back(temp);
    }

    getWarp();

    cout << f(0,0);


    return 0;
}