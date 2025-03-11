#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main(){

    Node *ptr1;
    ptr1 = new Node;
    ptr1->data = 52;
    ptr1->next = NULL;

    Node *ptr2;
    ptr2 = new Node;
    ptr2->data = 67;
    ptr2->next = NULL;

    Node *ptr3;
    ptr3 = new Node;
    ptr3->data = 99;
    ptr3->next = NULL;

    ptr1->next = ptr2;
    ptr2->next = ptr3;
    ptr3->next = ptr1;

    cout << ptr1->next->next->next->data;
    

}