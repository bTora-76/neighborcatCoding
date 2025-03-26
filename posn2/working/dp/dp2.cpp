#include <iostream>
#include <vector>
using namespace std;

int main(){

    int m,n;
    cin >> m >> n;

    vector <vector <int>> v(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> v[i][j];
        }
    }


    // loop จะตาม row
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            v[i][j] += max(v[i-1][j-1], v[i-1][j]);
        }
    }

    cout << v[m][n] << '\n';

    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}