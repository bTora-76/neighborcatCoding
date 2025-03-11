#include <iostream>
#include <string>
using namespace std;



struct Node{
    int data;
    Node *next;
    // constructor
    Node (int num){
        data = num;
        next = NULL;
    }
};

void print(Node *ptr){
    while (ptr!= NULL){
        cout << ptr->data << '\n';
        ptr = ptr->next;
    }

}

int main(){

    // 1 pointer, 2 nodes
    Node *ptr;

    Node *head;
    head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    
    // ตอนเริ่ม
    ptr = head;

    print(ptr);

    
    










    // Node *ptr2;
    // ptr2 = new Node;
    // ptr2->data = 67;
    // ptr2->next = NULL;

    // Node *ptr3;
    // ptr3 = new Node;
    // ptr3->data = 99;
    // ptr3->next = NULL;

    // ptr1->next = ptr2;
    // ptr2->next = ptr3;
    // ptr3->next = ptr1;

    
    

}