#include <iostream>
using namespace std;

int main(){
    // int x = 10;
    int *p;
    // p = &x;
    p = new int;
    delete(p);
    // change
    *p = 57;
    cout << *p;
}