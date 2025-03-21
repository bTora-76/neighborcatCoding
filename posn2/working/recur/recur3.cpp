#include <iostream>
using namespace std;

long long sum = 0;

void f(int n){
    ++sum;
    if (n == 0){
        return;
    }

    f(n-1);
    cout << n << " ";

}

int main(){

    int n;
    cin >> n;
    f(n);
    cout << sum;

}
