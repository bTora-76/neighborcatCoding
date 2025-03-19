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
    cout << node << " ";
    for (it = v[node].begin(); it != v[node].end();it++){
        if(visited[*it] == false){
            
            f(*it, v);
        }
    }
}

void bfs(int node, vector<vector<int>> &v){

    queue <int> q;

    q.push(node);
    visited[node] = true;
    
    while (!q.empty()){
        int t = q.front();
        q.pop();
        cout << t << " ";

        vector<int>::iterator it;
        for (it = v[t].begin(); it != v[t].end(); it++){
            if(visited[*it] == false){
                visited[*it] = true;
                q.push(*it);
            }
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

    while (true){
        char mode;
        int num; // node
        cin >> mode;
        if (mode == 'q') break;
        cin >> num;

        // reset visited
        fill(visited.begin(), visited.end(), false);

        // print starting node in ref
        
        if(mode == 'd'){
            
            f(num, adj);
            
        }

        else if (mode == 'b'){
            bfs(num, adj);
        }

        cout << '\n';
    }


    


 return 0;
}


// แก้ BFS