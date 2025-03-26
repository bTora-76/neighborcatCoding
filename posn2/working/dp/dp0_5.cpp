// fibo bottom up

#include <iostream>
#include <vector>
using namespace std;


int main(){
    long long n;
    cin >> n;   
    long long mem[3];
    mem[0] = 0;
    mem[1] = 1;



    for (long long i = 2; i <= n; i++){
        mem[i % 3] = mem[(i-2) % 3] + mem[(i-1) % 3];
    }

    cout << mem[n%3];

}