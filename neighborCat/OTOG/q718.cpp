#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;

int inputs[10002];

int mem[10002] = {0};

int n, poison;

int f(int index, int p){

    if (mem[index] != 0){return mem[index];}
    
    // dp แล้วไม่จำเป็น
    // if(index == 1) return inputs[1];
    // if(index == 2) return inputs[2];

    if (index <= 0) return 0;

    int x = 0;
    
    // check if first time
    if(index == n + 1){
        x = max(f(index - 1, p), x);
    } 

    if (p > 0){
        x = max(f(index - 1, p-1), x);
    }

    for (int i = index-2; i >= 1; i-- ){
        x = max(f(i, p), x);
    }

    return mem[index] = x + inputs[index];
}

int main(){

    
    cin >> n >> poison; 

    // 1-based index
    for (int i = 1; i <= n;i++){
        cin >> inputs[i];
    }

    mem[1] = inputs[1];
    // mem[2] = inputs[2];

    inputs[n+1] = 0;

    cout << f(n + 1,poison);  // position(day), number of poisons

}