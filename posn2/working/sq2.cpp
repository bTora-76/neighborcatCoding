#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector <queue <int>> v(n);

    for (int i = 0; i < q; i++){
        int mode, t, x;

        cin >> mode >> t;

        if(mode == 0){
            cin >> x;
            v[t].push(x);
        }
        else if (mode == 1){
            if(!v[t].empty()){
                cout << v[t].front() << '\n';
            }
        }
        else if (mode == 2){
            if(!v[t].empty()){
                v[t].pop();
            }
        }
    }
}