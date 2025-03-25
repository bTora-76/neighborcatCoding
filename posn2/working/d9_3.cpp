#include <iostream>
#include <vector>
using namespace std;


int rowMax, colMax, x;
void f(int i, int j, vector<vector<int>> &v){

    if(i < 0 || j < 0 || i == rowMax || j == colMax) return;    

    if (v[i][j] > x) return;
    
    v[i][j] = 999999;

    f(i-1,j,v);
    f(i+1,j,v);
    f(i,j-1,v);
    f(i,j+1,v);

}

int main(){

    
    cin >> rowMax >> colMax >> x;



    vector <vector <int>> v(rowMax, vector<int>(colMax, 0));

    for (int i = 0; i < rowMax; i++){
        int thisRow;
        cin >> thisRow;

        for (int j = 0; j < colMax; j++){
            v[i][j] += thisRow;
        }
    }

    for (int i = 0; i < colMax; i++){
        int thisCol;
        cin >> thisCol;

        for (int j = 0; j < rowMax; j++){
            v[j][i] += thisCol;
        }
    }

    // print check

    // for (int i = 0; i < rowMax; i++){
    //     for (int j = 0; j < colMax; j++){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    // loop start

    int c = 0;

    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if(v[i][j] <= x){
              ++c;
              f(i,j,v);  
            }
        }
    }

    cout << c;

}