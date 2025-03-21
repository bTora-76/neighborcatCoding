#include <iostream>
using namespace std;

long long sum = 0;

long long f(int n){
    ++sum;
    if(n == 0){
        return 0;
    }

    return n + f(n-1);

}

int main(){

    int i, n;
    cin >> i >> n;

    long long ans = i + f(n);

    cout << ans << " " << sum;

    return 0;
}