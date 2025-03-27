// bottom up -> f(n) = f(n-1) + f(n-4)

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector <long long> v;
vector <long long> mem;

long double findMean(long long i){
    
    if (i < 0) return 0;
    if(mem[i] != -1) return mem[i];
    
    return ((findMean(i-1) * i) + v[i])/(i+1);

}

int main(){

    long long n1;
    cin >> n1;

    mem.resize(n1+2, -1);

    v.resize(n1);
    for (long long i = 0; i < n1; i++){
        cin >> v[i];
    }
    long long newNum;
    cin >> newNum;
    v.push_back(newNum);

    cout << setprecision(2) << fixed << findMean(n1-1) << '\n';
    cout << findMean(n1);




    return 0;
}