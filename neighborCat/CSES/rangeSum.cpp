#include <iostream>
using namespace std;

int main(){

    long long n, k;
    cin >> n >> k;

    long long arr[n+1];
    arr[0] = 0;
    //preprocess

    for (long long i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    // query
    for (long long i = 0; i < k; i++){
        long long a,b;
        cin >> a >> b;
        cout << arr[b] - arr[a-1] << '\n';
    }

    return 0;
}