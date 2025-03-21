#include <iostream>
#include <string>
using namespace std;

long long sum = 0;

string s;

string f(int n){
    ++sum;
    //basecase
    if(n == -1){
        return "";
    }

    return  f(n-1) + f(n-1) + s[s.size()-n-1];
}

int main(){

    getline(cin, s);
    cout << f(s.size()-1) << '\n' << sum;

    return 0;
}