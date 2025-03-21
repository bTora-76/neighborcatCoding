#include <iostream>
#include <string>
using namespace std;

long long sum = 0;

string f(int n){
    ++sum;
    //basecase
    if(n == 0){
        return "";
    }

    return  f(n-1) + to_string(n) + " " + f(n-1);
}

int main(){

    int n;
    cin >> n;
    cout << f(n) << '\n' << sum - 1;

    return 0;
}