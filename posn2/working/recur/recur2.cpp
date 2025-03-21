#include <iostream>
using namespace std;


long long int sum = 0;

// positive
long long int f(long long int n){
    sum += 1;
    
    if(n == 0 || n == 1) return n;

    return f(n-1) + f(n-2);
    

}

int main(){
    long long int n;
    cin >> n;
    
    if (n < 0){
        cout << 0 << " " << n;
        return 0;
    }

    long long int ans = f(n); // ต้องเรียก f ก่อนมันจะได้บวก
    cout << sum << " " << ans;

    

}