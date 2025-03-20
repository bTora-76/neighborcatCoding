#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 10000;

int main(){

    int f, n;
    cin >> f >> n;

    vector<vector<int>> d(n+1, vector<int>(n+1,inf));

    vector <bool> hospitals(n+1, false);

    for (int i = 1; i <= f; i++){
        int t;
        cin >> t;
        hospitals[t] = true;
    }

    //set input
    for (int i = 0; i < n; i++){
        int a,b,w;
        cin >> a >> b >> w;

        d[a][b] = w;
        d[b][a] = w;
    }

    // set diagonal
    for (int i = 1; i <= n; i++) d[i][i] = 0;

    // loop k
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }



    // print check matrix

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}