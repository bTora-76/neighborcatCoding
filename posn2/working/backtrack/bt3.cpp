#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goal, n;
// i = current index

int c = 0;

void f(int index, vector <int> &v, int sum){

    if (sum == goal){
        ++c;
        return;
    }
    if (sum > goal) return; 

    for (int i = index + 1; i < v.size(); i++){
        sum += v[i];
        f(i,v,sum);
        sum -= v[i];
    }


}

int main(){

    
    cin >> goal >> n;

    vector <int> v(n);
    
    vector <bool> visited(n,false);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // if(v[v.size()-1] > goal) {
    //     cout << -1;
    //     return 0;
    // }

    for (int i = 0; i < v.size(); i++){
        f(i, v, v[i]);
    }

    if(c == 0) {
        cout << -1;
        return 0;
    }

    cout << c;

    

    return 0;
}