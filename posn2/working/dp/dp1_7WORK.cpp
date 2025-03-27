// bottom up

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector <vector<int>> mem;


int main(){

    int n;
    cin >> n;

    vector <int> v(n+1);

    mem.resize(n+1, vector<int>(n+1, -1));

    // base-1 index
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++){
        for (int l = 1; l <= n; l++){
            if(l == 0){
                mem[i][l] = 0;
            }
            if (l-i < 1){
                mem[i][l] = -999999;
            }

            mem[i][l] = max(mem[i][l-i] + v[i],  mem[i-1][l]);
        }
    }
    
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        cout << mem[i][j] << " ";
    }
    cout << '\n';
    }


    return 0;
}