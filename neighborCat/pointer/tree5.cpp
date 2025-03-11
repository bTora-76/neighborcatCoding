#include <iostream>
#include <string>
#include <queue>
using namespace std;



struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int num){
        data = num;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node *root){
    queue <Node*> q;

    q.push(root);

    while(!q.empty()){
        Node *t = q.front();
        cout << t->data << " ";
        q.pop();

        if (t->left != NULL) q.push(t->left);
        if (t->right != NULL) q.push(t->right);
    }

}

void preorder(Node *root){

    if (root == NULL) return;


    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);

}

void postorder(Node *root){

    if (root == NULL) return;


    

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";

}

// print จากซ้ายไปขวา
void inorder(Node *root){

    if (root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

    

}


Node* insert(Node *root,int data){

    if (root == NULL){
        return new Node(data);
    }

    queue <Node*> q;

    q.push(root);

    while(!q.empty()){
        Node *t = q.front();
        q.pop();

        if (t->left != NULL) q.push(t->left);
        else{
            t->left = new Node(data);
            return root;
        }

        if (t->right != NULL) q.push(t->right);
        else{
            t->right = new Node(data);
            return root;
        }
    }

    // ไม่ได้ใช้
    return root;

}

int main(){

    Node *root = new Node(25);

    root ->left = new Node(67);
    root->left->right = new Node(12);
    root->left->left = new Node(54);
    root->left->left->left = new Node(66); 
    root->left->left->left->left = new Node(95); 

    root->right = new Node(48);
    root->right->left = new Node(21);
    root->right->left->left = new Node(43);


    // update ค่า root
    root = insert(root, 6);
    BFS(root);

    return 0;
}