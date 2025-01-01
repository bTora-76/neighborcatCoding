#include <iostream>
#include <vector>
#include <string>
using namespace std;

int rowMax, colMax;
vector <int> bricks(21, 0);

void fillCol(int row,int col, vector <string> &mp){
    // basecase 
    if(row < 0 || row >= rowMax) return;
    if(mp[row][col] == 'O') return;

    

    fillCol(row +1, col, mp);

    if(bricks[col] > 0) mp[row][col] = '#';
    bricks[col] -= 1;


    
}

int main(){

    
    vector <string> mp;
    

    cin >> rowMax >> colMax;
    cin.ignore();

    for (int i = 0; i < rowMax; i++){
        string temp;
        getline(cin,temp);
        mp.push_back(temp);

    }

    for(int i = 0; i < colMax; i++){
        int temp;
        cin >> temp;
        bricks[i] = temp;
    }
    

    // make bricks fall

    for(int j = 0; j < colMax; j++){
        fillCol(0,j,mp);
    }


    // output

    for(int i = 0; i < rowMax; i++){
        for(int j = 0; j < colMax; j++){
            cout << mp[i][j];
        }
        cout << '\n';
    }
    


    return 0;
}