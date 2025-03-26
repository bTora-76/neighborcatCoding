#include <iostream>
#include <vector>
using namespace std;

vector <vector <int >>mem;

int c = 0;

int f(int i, int j, vector<vector<int>> &v){
    ++c;
    // cout << i << " " << j << '\n';
    //basecase 
    if (i <  -1 || j < -1) return 0;
    
    if(mem[i][j] != -1 ) return mem[i][j];

    
     //เพราะว่าโจทย์เป็น 1 index แต่เราใช้ 0 index


    return mem[i][j] = v[i][j] + max(f(i-1, j-1,v), f(i-1,j,v));




}

int main(){

    int m,n;
    cin >> m >> n;

    mem.resize(m, vector<int>(n,-1));

    vector <vector <int>> v(m, vector<int>(n));

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << f(m-1,n-1,v) << '\n'; // 0 index
    cout << c - 1 << '\n';

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << mem[i][j] << " ";
        }
        cout << '\n';
    }
    
    

    return 0;
}