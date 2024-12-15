//flood fill and backtracking
// เดินกลับมาเหยียบอันเดิมไม่ได้ = flood fill
// ถ้าเหยียบได้ใช้ backtracking

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <bool> check(100); 
int last;

// void showPath(int row, int col, vector <vector<int>> &check){
//   for (int i = 0; i < row; i++){
//     for (int j = 0; j < col; j++){
//       cout << check[i][j] << " ";
//     }
//     cout << '\n';
//   }
// }

int f(int node, vector<vector<int>> &v){
    //base case
    if (node == last) return 1;
    if (check[node] == true) return 0;
    //general case
    check[node] = true;

    // loop ในแต่ละรอบ
    vector <int>::iterator it;
    
    // ตัวแรกของแถวแรก
    // bool ans = false;
    int sum = 0;
    for(it = v[node].begin();it != v[node].end();it++){
        // if(!check[*it]){
        //     sum += f(node + 1);

        // }
        sum += f(*it,v);
        
    }

    check[node] = false;

    return sum;

}

int main(){
    int node,edge, start;
    cin >> node >> edge;

    vector<vector<int>> adj(node);


    //get input
    for(int i = 0; i < edge; i++){
        int num1,num2;
        cin >> num1 >> num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }

    cin >> start >> last;


    cout << f(start,adj);

  return 0;
}