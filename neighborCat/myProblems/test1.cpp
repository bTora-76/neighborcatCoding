#include <iostream>
using namespace std;

int n;

int f(int pos){
    // basecsae
    if (pos == 0) return 1;
    if (pos < 0) return 0;


    return f(pos-1) + f(pos-2);
}

int main(){

    cin >> n;

    cout << f(n);


    return 0;
}