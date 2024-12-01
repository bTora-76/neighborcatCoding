#include <iostream>
using namespace std;


int f(int p){

    if (p == 0)return 0; // คือถึงจุดหมาย

    if (p < 0) return 2000; // เกินจุดหมาย

    return 1 + min(min(f(p-3),f(p-5)) ,f(p-9));
}

int main(){
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}