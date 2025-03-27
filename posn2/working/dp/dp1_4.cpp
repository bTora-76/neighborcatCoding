#include <iostream>
#include <vector>
using namespace std;

// need to start from front

int n; 

vector<int> mem;

int f(int i, vector<int> &v){

    if (i >= n) return 99999;

    if(mem[i] != -1) return mem[i];
    
    int minVal = 99999;
    for (int j = 1; j <= v[i]; j++){
        // prevent redundant calling 
        if (i+j <= n-1 && mem[i+j] != -1) minVal = min(minVal, mem[i+j]);

        else{
            minVal = min(minVal, f(i + j,v));
        }
    }

    return mem[i] = minVal + 1;
    
}

int main(){

    
    
    
    cin >> n;
    mem.resize(n, -1);
    mem[n-1] = 0;

    vector<int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

   cout << f(0,v);

}