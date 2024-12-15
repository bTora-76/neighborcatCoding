#include <iostream>
#include <vector>
using namespace std;

int n;
vector <string> mp;
vector <vector < bool>> visited(35, vector<bool>(35,false));

int f(int row, int col){
    // base case คือเวลาคิดขอบ
    if (row < 0 || col < 0)return 0;
    if (mp[row][col] == 'X') return 0;
    // ป้องกันเดินซ้ำ
    if (visited[row][col] == true)return 0;
    visited[row][col] = true;

   
    return f(row - 1, col) + f(row, col - 1) + 1; // add 1 to account for the current block
}
   


int main(){

    cin >> n;

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        mp.push_back(temp);
    }

    cout << f(n-1,n-1);

    return 0;
}