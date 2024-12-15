//flood fill and backtracking
// เดินกลับมาเหยียบอันเดิมไม่ได้ = flood fill
// ถ้าเหยียบได้ใช้ backtracking

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <bool> check(100); 

// void showPath(int row, int col, vector <vector<int>> &check){
//   for (int i = 0; i < row; i++){
//     for (int j = 0; j < col; j++){
//       cout << check[i][j] << " ";
//     }
//     cout << '\n';
//   }
// }

void f(int node, vector<vector<int>> &v){
  
    check[node] = true;

    cout << node;
    //general case
    vector <int>::iterator it;
        
    for(it = v[node].begin();it != v[node].end();it++){
        if(check[*it] == false){f(*it, v);}
    }
}

int main(){
    int node,edge;
    cin >> node >> edge;

    vector<vector<int>> adj(node);


    //get input
    for(int i = 0; i < edge; i++){
        int num1,num2;
        cin >> num1 >> num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }

    f(0,adj);

  return 0;
}