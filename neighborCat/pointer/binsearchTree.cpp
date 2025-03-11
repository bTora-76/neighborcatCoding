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
    // เดินก่อนดู
    if (root == NULL) return new Node(data);

    // go left
    if (data < root->data){
        root->left = insert(root->left, data);
    }
    // go right
    if (data > root->data){
        root->right = insert(root->right, data);
    }

    return root;

}

Node* mostLeft(Node *root){

    while (root->left != NULL && root->right != NULL){
        root = root->left;
    }

    return root;


}

Node* delNode(Node *root,int data){
    // เดินก่อนดู
    if (root == NULL) return NULL;

    // go left
    if (data < root->data){
        root->left = delNode(root->left, data);
    }
    // go right
    else if (data > root->data){
        root->right = delNode(root->right, data);
    }

    else {
        if(root->left == NULL){
            Node* temp =  root->right;
            delete(root);
            return temp;
        }

        if(root->right == NULL){
            Node* temp =  root->left;
            delete(root);
            return temp;
        }

    }

    return root;

}

int main(){
    int arr[9] = {10, 8, 20, 3, 7, 9, 22, 18, 15};

    Node *root = NULL;


    for (int i = 0; i < 9; i++){
        root = insert(root, arr[i]);
    }

    


    // update ค่า root
    inorder(root);

    return 0;
}