#include <iostream>
#include <string>
#include <queue>
using namespace std;



struct Node{
    int data;
    Node *left;
    Node *right;
    // constructor -> จะเรียกแค่ว่าใช้ new
    Node (int num){
        data = num;
        left = NULL;
        right = NULL;
        
    }
};

void print(Node *root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node *f = q.front();
        cout << f->data << " ";
        q.pop();

        if(f->left != NULL){
            q.push(f->left);
        }
        if(f->right != NULL){
            q.push(f->right);
        }
       
    }


}

int main(){
    
    // mannual init

    Node *root = new Node(25);

    root->left = new Node(67);
    root->left->left = new Node(54);
    root->left->right = new Node(12);
    root->left->left->left = new Node(66);
    root->left->left->left->left = new Node(95);

    root->right = new Node(48);
    root->right->left = new Node(21);
    root->right->left->left = new Node(43);

    print(root);

    
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