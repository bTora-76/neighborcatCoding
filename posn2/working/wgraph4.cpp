#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 10000;

int main(){

    int n, e, threshold;
    cin >> n >> e >> threshold;

    vector<vector<int>> d(n, vector<int>(n,inf));

    //set input
    for (int i = 0; i < e; i++){
        int a,b,w;
        cin >> a >> b >> w;

        d[a][b] = w;
        d[b][a] = w;
    }

    // set diagonal
    for (int i = 0; i < n; i++) d[i][i] = 0;

    // loop k
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    vector<int> valids(n,0);

    // check restaurants with tresholds >> loop 2d
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            // exclude itself
            if (i != j && d[i][j] <= threshold){
                ++valids[i];
            }
        }
    }

    // print check matrix

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // for (int i = 0; i < n; i++){
    //     cout << valids[i];
    // }
    // cout << '\n';

    // check valids
    int minVal = 99999;
    int ansIndex = -9;

    for (int i = 0; i < n; i++){
        if (valids[i]== 0) continue;
        if(valids[i] < minVal){
            minVal = valids[i];
            ansIndex = i;
        }
        else if (valids[i] == minVal){
            if (i > ansIndex){
                ansIndex = i;
            }
        }
    }

    cout << ansIndex;
    return 0;
}