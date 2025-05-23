

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector <vector<int>> mem;

// use เลือก-ไม่เลือก
int f(int i, int l, vector <int> &v){

    if (l == 0) return 0; // บวกขากลับ
    if(l < 0 || i <= 0) return -99999;
    if(mem[i][l] != -1) return mem[i][l];

    // ไม่เลือก, เลือก
    return mem[i][l] = max(f(i,l-i,v) + v[i], f(i-1,l,v));



    

}

int main(){

    int n;
    cin >> n;

    vector <int> v(n+1);

    mem.resize(n+1, vector<int>(n+1, -1));

    // base-1 index
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    cout << f(n,n,v) << '\n';

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
        cout << mem[i][j] << " ";
    }
    cout << '\n';
    }



    return 0;
}