#include <iostream>
#include <string>
using namespace std;

string map;

// bool f(int p){
//     cout << p <<'\n';
    
//     if (p == 0)return true;

//     if (p < 0) return false;

//     // general case

//     bool canJump = false;

//     // ส่องก่อนแล้วโดด

//     // -1 is to account for string index
//     if (p-3 >= 0 && map[p-3 - 1] == '.'){
//         cout << map[p-3-1] << " : 3" << '\n';
//         canJump = canJump || f(p-3);
//     }

//     if (p-5 >= 0 && map[p-5 - 1] == '.'){
//         cout << map[p-5-1] << " : 5" << '\n';
//         canJump = canJump || f(p-5);
//     }

//     if (p-9 >= 0 && map[p-9 - 1] == '.'){
//         cout << map[p-9-1] << " : 9" << '\n';
//         canJump = canJump || f(p-9);
//     }
//     cout << "B: " << p << "\n";
//     return canJump;
// }

//โดดแล้วส่อง 

bool f2(int p){

    if (p == 0)return 1;

    if (p < 0) return 0;

    if (map[p-1] == '#') return 0;

    return f2(p-3) || f2(p-5) || f2(p-9);
}

int main(){
    getline(cin,map);
    int n;
    cin >> n;
    cout << f2(n);

    return 0;
}