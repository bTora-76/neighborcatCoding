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

Node* arr[30] = {NULL};
pair<int,int> lr[30]; 


int getSibling(Node* root){
    // absolute root
    if (root->parent == -1) return -1;
    if(arr[root->parent]->left == NULL || arr[root->parent]->right == NULL) return -1;

    
    return arr[root->parent]->left == root ? arr[root->parent]->right->data : arr[root->parent]->left->data;
}

// degree is the number of children at next level only
int getDegree(Node *root){
    int sum = 0;
    if(root->left != NULL) ++sum;
    if(root->right != NULL) ++sum;

    return sum;
}

int depth;

// int getDepth(Node* root, int id, int layer){
//     cout << root->data << " " << id << '\n';
    
//     if (root == NULL) return 0;

//     if(root->data == id){
//         return layer;
//     }

//     if(root->data != id) {
//         return 0;
//     }

//     return max(getDepth(root->left, id, layer + 1), getDepth(root->right, id, layer + 1));
// }

int getDepth(Node* root, int id, int layer){
   if (root == NULL) return -1;
   if(root->data == id) return layer;

   int leftD = getDepth(root->left, id, layer + 1); 
   int rightD = getDepth(root->right, id, layer + 1); 

   if(leftD != -1) return leftD;
   if (rightD != -1) return rightD;
   // both are -1
   return -1;
}

int getHeight(Node* root, int height = 0){
    // cout << layer << " ";

    if (root == NULL) return -99;
    
    if(root->left == NULL && root->right == NULL){
        return height;
    }

    return max(getHeight(root->left, height + 1), getHeight(root->right, height + 1));
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

    Node* root;

    // cout << getDepth(arr[])

    for (int i = 0; i < n; i++){
        // cout << "i = " << i << "cur = " << arr[i]->data << " parent is " << arr[i]->parent << endl;
        if(arr[i]->parent == -1){
            root = arr[i];
            break;
        }
    };
    // print check
    // for (int i = 0; i < n; i++){
    //     cout << arr[i]->data << " : " << lr[i].first << ',' << lr[i].second << '\n';
    // }

    //print parent
    // for (int i = 0; i < n; i++){
    //     cout << arr[i]->data << ",";
    //     cout << arr[i]->parent << " " << endl;
    // }

    // cout << getSibling(arr[0]);
    // cout << getHeight(arr[1]);
    // cout << getDepth(root, 5, 0);
    
    
    for(int i = 0; i < n; i++){


        cout << "node " << i << ": parent = " << arr[i]->parent << ", sibling = " << getSibling(arr[i]) << ", degree = " << getDegree(arr[i]) 
        << ", depth = " << getDepth(root, i,0) << ", height = " << getHeight(arr[i]) << ", ";

        if(arr[i]->parent == -1) cout << "root";
        else if(arr[i]->left == NULL && arr[i]->right == NULL) cout << "leaf";
        else cout << "internal node";

        cout << '\n';
    }
    

    return 0;
}

