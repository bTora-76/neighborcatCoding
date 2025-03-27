// bottom up -> f(n) = f(n-1) + f(n-4)

#include <iostream>
#include <vector>
using namespace std;



int main(){

    

    long long n;
    cin >> n;

    vector <long long> mem(n+1,-1); // 1-index
    mem[1] = 1;

    if (mem[n] != -1){
        cout << mem[n];
        return 0;
    }

    long long adder = 5;

    for (long long i = 2; i <= n; i++){
        mem[i] = mem[i-1] + adder;
        adder += 4;
    }

    cout << mem[n];

    

    return 0;

}