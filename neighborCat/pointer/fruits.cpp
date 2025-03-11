#include <iostream>
#include <string>
using namespace std;

struct fruit{
    int weight; 
    string name;
};

int main(){
    fruit *ptr1;
    ptr1 = new fruit;

    fruit *ptr2;
    ptr2 = new fruit;

    cin >> ptr1->weight >> ptr1->name;
    cin >> ptr2->weight >> ptr2->name;

    if (ptr1->weight > ptr2->weight){
        cout << ptr1->name;
    }
    else cout << ptr2->name;

    cout << " is heavier.";

}