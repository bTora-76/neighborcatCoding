#include <iostream>
#include <vector>
using namespace std;

int r = 0;
int s = 0;

void f(int n, vector <int> &v){
    ++r;
    if(n == 2) return;

    for (int i = 0; i < v.size() - 1 - (v.size()-n); i++){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
            ++s;
        }
    }

    f(n-1,v);

}

int main(){

     int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    f(n, v);

    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout <<  r + 1<< " " << s;



    

    return 0;
}