// bottom up -> f(n) = f(n-1) + f(n-4)

#include <iostream>
#include <vector>
using namespace std;



int main(){

    

    long long n;
    cin >> n;

    vector <long long> mem(4+n,-1); // จองเผื่อไปเลย
    mem[1] = 1;
    mem[2] = 1;
    mem[3] = 1;
    mem[4] = 2;

    if (mem[n] != -1){
        cout << mem[n];
        return 0;
    }

    for (long long i = 5; i <= n; i++){
        mem[i] = mem[i-1] + mem[i-4];
    }

    cout << mem[n];

    

    return 0;

}