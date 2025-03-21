#include <iostream>
#include <string>
using namespace std;

long long sum = 0;

double f(int n){
    ++sum;

    if (n == 1) return 0;

    return 1 + f(n/2);

}

int main(){

    int n;
    cin >> n;

    double ans = f(n);
    cout << sum << " " <<  ans;

    return 0;
}