#include <iostream>
#include <string>
using namespace std;

// preorder =  วิ่งก่อน print

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

    // basecase
    if(root == NULL)return;

    
    print(root->left);
    cout << root->data << " ";
    print(root->right);

}

int main(){
    
    // mannual init

    Node *root = new Node(10);

    root->left = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->right = new Node(7);
 

    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->right = new Node(22);

    print(root);

    
    // ตอนเริ่ม
    


}