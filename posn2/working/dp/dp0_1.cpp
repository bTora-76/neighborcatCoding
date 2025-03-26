#include <iostream>
#include <vector>
using namespace std;

vector <vector <long long >>mem;

long long c = 0;

long long f(long long i, long long j, vector<vector<long long>> &v){
    ++c;
    // cout << i << " " << j << '\n';
    //basecase 
    if (i == -1 || j == -1) return 0;
    
    if(mem[i][j] != -1 ) return mem[i][j];

    
     //เพราะว่าโจทย์เป็น 1 index แต่เราใช้ 0 index


    return mem[i][j] = v[i][j] + max(f(i-1, j-1,v), f(i-1,j,v));




}

int main(){

    long long m,n;
    cin >> m >> n;

    mem.resize(m, vector<long long>(n,-1));

    vector <vector <long long>> v(m, vector<long long>(n));

    for (long long i = 0; i < m; i++){
        for (long long j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << f(m-1,n-1,v) << '\n'; // 0 index
    cout << c - 1 << '\n';

    for (long long i = 0; i < m; i++){
        for (long long j = 0; j < n; j++){
            cout << mem[i][j] << " ";
        }
        cout << '\n';
    }
    
    

    return 0;
}