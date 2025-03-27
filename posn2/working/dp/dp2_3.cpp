// bottom up -> f(n) = f(n-1) + f(n-4)

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector <vector <int>> mem;

int R, C;

int f (int i, int j, vector<vector <int>> &v){
    // check bound
    if(i == C) return 0; //correct
    if(i < 0 || i == R || j < 0 || j == C)return -9999;
    if(mem[i][j] != -1) return mem[i][j];
    

    return mem[i][j] = max(f(i+1,j-1,v), max( f(i+1,j,v), f(i+1, j+1,v))) + v[i][j]; // บวกขากลับ
}


int main(){

    
    cin >> R >> C;
    mem.resize(R, vector<int>(C, -1));

    vector<vector <int >> v(R,vector<int>(C));
    for (int i = 0; i < R ; i++){
        for (int j = 0; j < C; j++){
            cin >> v[i][j];
        }
    }

    int maxVal = 0;

    

    for (int i = 0; i < C; i++){
        maxVal = max(maxVal, f(0,i,v));
    }

    cout << maxVal;


    return 0;
}