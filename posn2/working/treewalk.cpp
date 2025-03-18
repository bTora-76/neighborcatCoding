#include <iostream>
#include <vector>
using namespace std;



struct Node{
    int data;
    Node *left;
    Node *right; 
    int parent;
    Node(int num, int p = -1){
        data = num;
        left = NULL;
        right = NULL;
        parent = p;
    }
};

Node* arr[100] = {NULL};

Node* insert(Node *root,int ID, int lID, int rID){
    //basecase

    if (root == NULL) return NULL;

    if (root->data == ID){
        if(lID == -1) root->left = NULL;
        else {
            root->left = new Node (lID);
        }
        if(rID == -1) root->right = NULL;
        else {
            root->right = new Node (rID);
        }
        return root;
    }

    // ถ้า insert left แล้ว left เป็น NULL ก็จะ return NULL กลับมาอยู่ดี
    root->left = insert(root->left, ID, lID, rID); 
    root->right = insert(root->right, ID, lID, rID);
}

void inorder(Node *root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if (root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// find node function
bool f(Node* root, int ID){
    if (root == NULL) return false;

    if (root != NULL && root->data == ID){
        return true;
    }

    return (f(root->left, ID) || f(root->right, ID));
}



int main(){

    Node *root = NULL; 

    int n;
    cin >> n;

   

    // the 0th iteration, create new node
    int id, Lid, Rid;
    // cin >> id >> Lid >> Rid;

    // root = new Node(id);
    // root->left = new Node(Lid);
    // root->right = new Node(Rid);

    // arr[id] = root;


    for (int i = 0; i < n; i++){
        cin >> id >> Lid >> Rid;
        // haven't been created
        
        if (arr[i] == NULL){
            arr[i] = new Node(id);

            if (Lid == -1){
                arr[i]->left = NULL;
            }
            else{
                arr[i]->left = new Node(Lid);
            }
            if (Rid == -1){
                arr[i]->right = NULL;
            }
            else{
                arr[i]->right = new Node(Rid);
            }
        }
        
    }

    for (int i = 0; i < n; i++){
        if (lr[i].first == -1 ){
            arr[i]->left = NULL;
        }
        else{
            arr[i]->left = arr[lr[i].first];
            arr[lr[i].first]->parent = arr[i]->data;
        }

        if (lr[i].second == -1 ){
            arr[i]->right = NULL;
        }
        else{
            arr[i]->right = arr[lr[i].second];
            arr[lr[i].second]->parent = arr[i]->data;
        }
    }

    // printing

    // for (auto e : arr){
    //     cout << e << " " << e->data << '\n';
        
    // }

    for (int i = 0; i < n; i++){
        cout << sum(arr[i]) << " ";
    }

    // cout << "Preorder\n";
    // preorder(root); 
    // cout << "\n";
    // cout << "Inorder\n";
    // inorder(root); 
    // cout << "\n";
    // cout << "Postorder\n";
    // postorder(root); 
    // cout << "\n";




    return 0;

}