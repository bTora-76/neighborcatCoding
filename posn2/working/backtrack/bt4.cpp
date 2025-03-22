// permutation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, light;
// i = current index

int c = 0;

void f(int index, vector <bool> &mp, int l){
    if(l == 0) ++c;
    if (l < 0) return;

    

    for (int i = index - 1; i >= 0; i--){
    mp[i] = true; // วางไฟไปแล้ว
    f(i,mp,l-1);
    mp[i] = false; // reset กลับ

    

    }
    
}


int main(){
    cin >> n >> light;

    vector <bool> mp(n+1,false);

    f(n, mp, light);
    
    cout << c;

    return 0;
}