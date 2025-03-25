#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    int depth, x;
    cin >> depth >> x;
    int k = x;
    --k;

    vector <int> v(depth);

    // turn to reversed binary (dont have to reverse cuz this algorithm already gives us binary in revere order)
    // don't worry about padding, this also already does it
    for (int i = 0; i < depth; i++){
        int r = k % 2;
        v[i] = r;
        k = k/2;
    }

    // for (int e : v) cout << e << " ";

    // combine
    int finalNum = 0;
    for (int i = 0; i < depth; i++){
        finalNum += (v[i] * (1 << (depth - i - 1)));

    }

    cout << finalNum;

    // cout << (pow(2,depth-1) + k-1)  %  ;    


}