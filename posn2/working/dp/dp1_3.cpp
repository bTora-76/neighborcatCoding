#include <iostream>
#include <vector>
using namespace std;

vector <vector <long long >>mem;

long long f(long long i, long long j){
    if (i == 0 || j == 0 ) return 0;
    if (i == 1 && j == 1) return 1;

    if(mem[i][j] != -1) return mem[i][j];

    return mem[i][j] = f(i-1,j) + f(i,j-1);

}

int main(){

    long long m,n;
    cin >> m >> n;

    mem.resize(m+1, vector<long long>(n+1,-1));

    cout << f(m,n);

     // 1 index

    return 0;
}