#include <iostream>
#include <vector>
#include <algorithm>
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
pair<int,int> lr[100]; 
// vector <pair<int,pair<int,int>>> lr; // node, L ,R
 


// create tree
// Node* create(Node* root){
//     // is leaf
//     if (root->left == NULL && root->right == NULL)return root;

    




//     return root;
// }


void inorder(Node *root){
    if (root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){
    // cout << root->data;
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


int main(){

    

    int n;
    cin >> n;

    // make arr and pair vector
    for (int i = 0; i < n; i++){
        int id, Lid, Rid;
        cin >> id >> Lid >> Rid;

        // เรารู้ว่า 1 node จะ input รอบเดียวดังนั้นไม่ต้อง check ว่า = null?
        arr[id] = new Node(id);
        
        lr[id] = {Lid, Rid};
    }

    

    //สั่งชี้


    // for (auto e : lr){
    //     cout << e.first << " " << e.second << '\n';
    // }

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
    // find root node and set root node

    Node* root;

    for (int i = 0; i < n; i++){
        // cout << "i = " << i << "cur = " << arr[i]->data << " parent is " << arr[i]->parent << endl;
        if(arr[i]->parent == -1){
            root = arr[i];
            break;
        }
    };

    // cout << "this is root " << root->data << endl;

//-------------------------------------------------------------

    cout << "Preorder\n";
    preorder(root); 
    cout << "\n";
    cout << "Inorder\n";
    inorder(root); 
    cout << "\n";
    cout << "Postorder\n";
    postorder(root); 
    cout << "\n";







    // print parents
    // for (int i = 0; i < n; i++){
    //     cout << arr[i]->data << ",";
    //     cout << arr[i]->parent << " " << endl;
    // }


    return 0;
}



//  for (int i = 0; i < n; i++){
//                 Node* curLeft = arr[i]->left;
//                 if (curLeft->data == Lid){
//                     arr[i]->left = curLeft;
//                     break;
//                 }

//             }