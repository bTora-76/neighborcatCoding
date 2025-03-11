#include <iostream>
using namespace std;

struct product{
    int weight;
    float price;
};

int main(){

    // product a;
    // a.weight = 5;
    // a.price = 10;

    product *ptr; // pointer that points to a

    // ใช้พื้นที่ที่จองมาใหม่
    ptr = new product;
    

    ptr->weight = 57;
    ptr->price = 200;

    cout << ptr->weight <<  " " << ptr->price;
    

}