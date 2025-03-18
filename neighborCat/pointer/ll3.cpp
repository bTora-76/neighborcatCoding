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
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << '\n';

}

int n;

void pop_front(Node *head){
    Node *ptr = head->next;
    head->next = head->next->next;
    delete(ptr);

}

void pop_back(Node *ptr){
    Node *temp;

    while (ptr->next->next != NULL){ 
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = NULL;
    delete(temp);

}

void push_back(Node *ptr, int num){
    while (ptr->next != NULL){ 
        ptr = ptr->next;
    }

    ptr->next = new Node(num);


}

void push_front(Node *ptr, int num){
    Node *nextNode = ptr->next;
    ptr->next = new Node(num);
    ptr->next->next = nextNode;
}

int getSize(Node *ptr){
    int count = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        ++count;
    }
    return count;

};

int main(){
    
    cin >> n;

    // 1 pointer, 2 nodes
    Node *ptr;

    Node *head; 
    head = new Node(0);

    ptr = head;
    int num;

    Node *temp;

    print(head);

    
    // for (int i = 0; i < n; i++){
    //     cin >> num;
    //     temp = new Node(num);
    //     ptr->next = temp; // connect nodes
    //     ptr = temp; // move ptr
    // }

    // Node *temp;
    // temp = new Node(5);

    // ptr->next = temp;
    // ptr = ptr->next;
    // // ptr = temp; ก็ได้v

    // temp = new Node(6);
    // ptr->next = temp;
    // ptr = ptr->next;

    // temp = new Node(8);
    // ptr->next = temp;
    // ptr = ptr->next;


    
    
    cout << getSize(head);


    

    
    // ตอนเริ่ม
    


    
    










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