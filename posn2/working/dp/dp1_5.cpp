//top down exceeded time limit

#include <iostream>
#include <vector>
using namespace std;

vector <int> mem;

// state is row
int f(int i){
    if(mem[i] != -1){
        return mem[i];
    }

    int sum = 0;

    // วิ่งตั้ง
    if(i >= 4){
        sum += f(i-4);
    }   

    sum += f(i-1);

    return mem[i] = sum;

}

int main(){

    

    int n;
    cin >> n;

    mem.resize(n+1,-1);
    mem[0] = 1;

    cout << f(n) << "\n";

    for (auto e : mem){
        cout << e << " ";
    }

    return 0;

}