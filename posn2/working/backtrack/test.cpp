#include <iostream>
#include <vector>
using namespace std;

void f(vector <int> &v, int l, int r){
    
    if (l == r){

        if(v[v.size()/2] == 2){
            for (int e : v){
                cout << e;
            }
            cout << '\n';
        }
    }

    for (int i = l; i <= r; i++){
        swap(v[i],v[l]);
        f(v, l+1, r);
        swap(v[i],v[l]);

    }

}


int main(){

    vector <int> v = {1,2,3};

    f(v, 0, v.size()-1);

    
}