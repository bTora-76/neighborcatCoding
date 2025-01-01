#include <iostream>
#include <vector>
using namespace std;

bool check[25][25];
int m;

// for(int i = 0; i < m; i++){
//         for(int j = 0; j < m; j++){
//             cout << check[i][j];
//         }
//         cout << '\n';
//     }

//     system("pause");

int f(int row, int col, vector <vector <int>> &mp, int preTemp){
    // technique โดดไปเลย + floodfill
    //base case
    if(row < 0 || col < 0 || row >= m || col >= m) return -5; // border
    if(mp[row][col] == 100 || check[row][col] == true) return -5;
    if(mp[row][col] <= preTemp) return -5;

    check [row][col] = true;
    preTemp = mp[row][col]; // change previous temp to the current one
    
    // choice
    return  max(mp[row][col],max(f(row,col-1,mp, preTemp),max(f(row,col+1,mp,preTemp), max(f(row+1,col,mp,preTemp), f(row-1,col,mp,preTemp)))));
}

int main(){
    // starting coordinates
    int x, y;
    cin >> m >> x >> y;

    vector <vector <int>> mp(m, vector<int>(m,0));

    

    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            int temp;
            cin >>temp;
            mp[i][j] = temp;
        }
    }

    cout << f(y-1,x-1,mp,-6); //pretemp ตัวแรกต้องน้อยกว่าช่องแรก (mp[y-1][x-1]-1) หรือ set เป๋นค่าน้อยๆเลยก็ได้จะได้ไม่ติด
    return 0;
}