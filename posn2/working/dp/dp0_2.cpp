#include <iostream>
#include <vector>
using namespace std;

int main(){

    long long m,n;
    cin >> m >> n;

    vector <vector <long long>> v(m+1, vector<long long>(n+1, 0));

    for (long long i = 1; i <= m; i++){
        for (long long j = 1; j <= n; j++){
            cin >> v[i][j];
        }
    }


    // loop จะตาม row
    for (long long i = 1; i <= m; i++){
        for (long long j = 1; j <= n; j++){
            v[i][j] += max(v[i-1][j-1], v[i-1][j]);
        }
    }

    cout << v[m][n] << '\n';

    for (long long i = 1; i <= m; i++){
        for (long long j = 1; j <= n; j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}