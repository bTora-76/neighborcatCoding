#include <iostream>
using namespace std;


long long int sum = 0;

long long int  f(long long int  n){
    
    sum += 1;
    
    if(n == 1) return 1;

    return (n*n) + f(n-1);

}

int main(){
    int n;
    cin >> n;
    
    long long int  ans = f(n); // ต้องเรียก f ก่อนมันจะได้บวก
    cout << 2 * sum << " " << ans;

    

}