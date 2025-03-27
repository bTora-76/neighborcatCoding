// bottom up -> f(n) = f(n-1) + f(n-4)

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector <long long> v;
vector <long long> mem;

// use เลือก-ไม่เลือก
int f(int i, int l, vector <int> &v){

    if (l == 0) return 0; // บวกขากลับ
    if(l < 0 || i < 0) return -99999;

    // ไม่เลือก, เลือก
    return max(f(i,l-i,v) + v[i], f(i-1,l,v));



    

}

int main(){

    int n;
    cin >> n;

    vector <int> v(n+1);
    // base-1 index
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }

    cout << f(n,n,v);



    return 0;
}