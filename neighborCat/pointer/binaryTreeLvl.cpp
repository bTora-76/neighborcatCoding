// fill by level order

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

// ต้อง return เป็น ptr เพราะ root hasn't been globally declared
Node* insert(Node* root, int data){

    if(root == NULL) return new Node(data); // create only root then ret

    queue <Node*> q;
    q.push(root);


    while(!q.empty()){
        Node *f = q.front();
        q.pop();
        // if คือวิ่งลงมาเฉยๆๆ
        if(f->left != NULL){
            q.push(f->left);
        }
        // ถ้าใน database มีแต่ใน tree ยังไม่มี, เพิ่มแค่ 1 ตัว
        else{
            f->left = new Node(data); // left ตัวนี้เป็น NULL
            return root;
        }
        if(f->right != NULL){
            q.push(f->right);
        }
        else{
            f->right = new Node(data); // left ตัวนี้เป็น NULL
            return root;
        }
        
    }

    return root;


}


int main(){
    
    // mannual init

    Node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);


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