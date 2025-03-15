#include <iostream>
#include <vector>
using namespace std;


int arr[65][65];

int maxCol, maxRow;

void f(int row, int col, vector <string> &v){
    // มองก่อนเดิน

    // border basecase
    

    // can change to any character just not p
    v[row][col] = '*';

    if(row + 1 < maxRow && v[row + 1][col] == 'P' ) f(row+1, col, v);
    if( row - 1 >= 0 && v[row - 1][col] == 'P' ) f(row -1, col, v);
    if(col + 1 < maxCol && v[row][col + 1] == 'P' ) f(row, col+1, v);
    if(col - 1>= 0 && v[row][col - 1] == 'P' ) f(row, col-1, v);



}


int main(){
    // includes padding
    for (int i = 0; i <= 64; i++){
        for (int j = 0; j <= 64; j++){
            arr[i][j] = 0;
        }
    }

   
    cin >> maxCol >> maxRow; 

    // input
    vector <string> v(maxRow);

    for (int i = 0; i < maxRow; i++){
        cin >> v[i];
    }
    // get started for prefix sum
    // base-0 index cuz we're doing vector
    for (int i = 0; i < maxRow; i++){
        for (int j = 0; j < maxCol; j++){
            if (v[i][j] == 'T'){
                arr[i+1][j+1] = 1;
            }
        }
    }

    // preprocess
    for (int i = 1; i <= maxRow; i++){
        for (int j = 1; j <= maxCol; j++){
          arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }

    //output
    // for (int i = 1; i <= maxRow; i++){
    //     for (int j = 1; j <= maxCol; j++){
    //       cout << arr[i][j];
    //     }
    // cout << '\n';
    // }


    // check max area

    int maxArea = 0;
    

    // find max area (done)

    vector <vector <int>> coords;

    for (int y1 = 1; y1 <= maxRow; y1++){
        for (int x1 = 1; x1 <= maxCol; x1++){
            int maxK = min(maxCol - x1, maxRow - y1);
            for (int k = 0; k <= maxK; k++){
                    int y2 = y1 + k;
                    int x2 = x1 + k;
                    int trees = arr[y2][x2] - arr[y2][x1-1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1];
                    // valid
                    if (trees == 0){
                        if ((x2 - x1 + 1) * (y2 - y1 + 1) > maxArea){
                            maxArea = (x2 - x1 + 1) * (y2 - y1 + 1);
                        }
                }
            }
        }
    }

    // find coords of max area (correct)

    for (int y1 = 1; y1 <= maxRow; y1++){
        for (int x1 = 1; x1 <= maxCol; x1++){
            int maxK = min(maxCol - x1, maxRow - y1);
            for (int k = 0; k <= maxK; k++){
                    int y2 = y1 + k;
                    int x2 = x1 + k;
                    int trees = arr[y2][x2] - arr[y2][x1-1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1];
                    // valid
                    if ((x2 - x1 + 1) * (y2 - y1 + 1) == maxArea && trees == 0){
                        coords.push_back({x1,y1,x2,y2});
                    }
                }
            }
    }

    //store coordinate of max areas (x1,y1,x2,y2)
    
    // for (int i = 0; i < coords.size(); i++){
    //     for (int j = 0; j < 4; j++){
    //         cout << coords[i][j] << " ";
    //     }
    //     cout << '\n';
    // }


    // loop in v but use index of the max area
    
    // return 0;
    int minPond = 999;
    
    // problem is here
    for (int k = 0; k < coords.size(); k++){
        vector <string> x = v;
        int pond = 0;
        for (int i = coords[k][1] - 1; i < coords[k][3]; i++){
            for(int j = coords[k][0] - 1; j < coords[k][2]; j++){
                if(x[i][j] == 'P'){
                    ++pond;
                    f(i,j,x);
                }
            }
        }
        minPond = min(pond, minPond);
    }

    

    
    if (minPond == 999) minPond = 0;
    
    // cout << "HELLO\n";
    cout << maxArea << " " << minPond;


    


    return 0;

}