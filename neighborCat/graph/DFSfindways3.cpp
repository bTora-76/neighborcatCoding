//flood fill and backtracking
// เดินกลับมาเหยียบอันเดิมไม่ได้ = flood fill
// ถ้าเหยียบได้ใช้ backtracking


// backtracking หาระยะทางที่สั้นที่สุด

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

// 

int f(int node, vector<vector<int>> &v){
    //มองก่อนเดิน
    //base case
    if (node == last) return 0;
    

    // loop ในแต่ละรอบ
    vector <int>::iterator it;
    
    // ตัวแรกของแถวแรก
    // bool ans = false;
    int minVal = 2000;
    for(it = v[node].begin();it < v[node].end();it++){
        if (check[*it] == false){
            check[*it] = true;
            minVal = min(minVal,f(*it,v));
            check[*it] = false;
        }
        
        
    }
    return minVal + 1;

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

    //กันไมา่ให้วิ่งกลับไปกลับมาตรง 0
    check[start] = true;

    cout << f(start,adj);

  return 0;
}

// 6 7
// 0 1
// 1 4
// 1 2
// 2 4
// 2 3
// 3 4
// 4 5
// 0 5