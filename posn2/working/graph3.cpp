#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <bool> visited(100,false);

// DFS
void f(int node, vector<vector<int>> &v){
    
    if (visited[node] == true){
        return;
    }
    // choice
    visited[node] = true;
    vector<int>::iterator it;

    for (it = v[node].begin(); it != v[node].end();it++){
        if(visited[*it] == false){
            cout << *it << " ";
            f(*it, v);
        }
    }
}


int main(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n); // n,weight


    // ไม่ต้อง push 2 ข้างเพราะโจทย์จะให้ข้อมูลมาเอง
    while (true){
        char mode;
        int a, b, w;

        cin >> mode;
        if (mode == 's') break;

        cin >> a >> b >> w;

        adj[a].push_back(b);
    }

    

    


    // BFS >> if traversal there's no need for pq, but teacher said grader uses pq's ans

    for (int i = 0; i < n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    // for (int i = 0; i < n;i++){
    //     for (int j = 0; j < adj[i].size(); j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << '\n';
    // }


    // test 1 iteration

    for (int i = 0; i < n; i++){
        if (visited[i] == false){
            cout << i << " ";
            // วิ่ง DFS
            f(i, adj);

           
        cout << '\n';
        }


    }


 return 0;
}