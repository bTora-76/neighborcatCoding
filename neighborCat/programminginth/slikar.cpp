#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    
    int rowMax, colMax;
    cin >> rowMax >> colMax;

    vector <string> mp(rowMax);

    pair <int,int> end;    
    

    for (int i = 0; i < rowMax; i++){
        cin >> mp[i];
    }

    // for (string e: mp){
    //     cout << e << '\n';
    // }

    //preprocessed water

    int water[rowMax][colMax];

    // just to be safe when comparing visited
    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            water[i][j] = 2510;
        }
    }

    pair<int,int> start;
    

    queue <pair<int,int>> q;

    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            if (mp[i][j] == 'S'){
                start = {i,j};
            }
            else if (mp[i][j] == 'D'){
                end = {i,j};
            }
            else if (mp[i][j] == '*'){
                water[i][j] = 0;
                //push coordinate into queue
                q.push({i,j});
            } 
        }
    }

    while(!q.empty()){
        // should check before move
        
        // check border
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        int newVal =  water[row][col] + 1;
    

        if (row + 1 < rowMax && newVal < water[row + 1][col] &&  mp[row + 1][col] != 'D' && mp[row + 1][col] != 'X'){
            water[row + 1][col] =  newVal;
            q.push({row+1, col});
        }

        if (row - 1 >= 0 && newVal < water[row - 1][col] &&  mp[row - 1][col] != 'D' && mp[row - 1][col] != 'X'){
            water[row - 1][col] = newVal;
            q.push({row-1, col});
        }

        if (col + 1 < colMax  && newVal < water[row ][col + 1] &&  mp[row][col + 1] != 'D' && mp[row][col+1] != 'X'){
            water[row][col + 1] = newVal;
            q.push({row, col + 1});
        }

        if (col - 1 >= 0 && newVal < water[row ][col - 1] &&  mp[row][col - 1] != 'D' && mp[row][col-1] != 'X'){
            water[row][col - 1] = newVal;
            q.push({row, col - 1});
        }

    }
    // water done----------

    // for (int i = 0 ; i < rowMax; i++){
    //     for (int j = 0; j < colMax; j++){
    //         cout << water[i][j];
    //     }
    //     cout << '\n';
    // }

    //walking

    

    q.push(start);

    int minutes[rowMax][colMax];
    

    for (int i = 0; i < rowMax; i++){
        for (int j = 0; j < colMax; j++){
            minutes[i][j] = 2510;
        }
    }

    minutes[start.first][start.second] = 0;

    while (!q.empty()){
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        int newVal =  minutes[row][col] + 1;

        if (row + 1 < rowMax && newVal < minutes[row + 1][col] &&  newVal < water[row+1][col] && mp[row+1][col] != 'X'){
            minutes[row + 1][col] = newVal;
            q.push({row+1, col});
        }

        if (row - 1 >= 0 && newVal < minutes[row - 1][col] && newVal < water[row-1][col]  && mp[row-1][col] != 'X'){
            minutes[row - 1][col] = newVal;
            q.push({row-1, col});
        }

        if (col + 1 < colMax && newVal < minutes[row ][col + 1] && newVal < water[row][col + 1] && mp[row][col + 1] != 'X'){
            minutes[row][col + 1] = newVal;
            q.push({row, col + 1});
        }

         if (col - 1 >= 0 && newVal < minutes[row][col- 1] && newVal < water[row][col - 1]  && mp[row][col - 1] != 'X'){
            minutes[row][col - 1] = newVal;
            q.push({row, col - 1});
        }

        if (minutes[end.first][end.second] < 2510){
            cout << minutes[end.first][end.second];
            return 0;
        }

    }


    cout << "KAKTUS";


    return 0;
}