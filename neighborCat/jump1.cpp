#include <iostream>
using namespace std;


bool f(int p){

    if (p == 0)return 1;

    if (p < 0) return 0;

    return f(p-3) || f(p-5) || f(p-9);
}

int main(){
    int n;
    cin >> n;
    cout << f(n);

    return 0;
}