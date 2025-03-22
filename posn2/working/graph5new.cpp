#include <iostream>
#include <vector>
#include <queue>
using namespace std;




vector <int> zones(50,0);
vector <int> parent(50,-1);
vector <bool> visited(50,false);

int n;

int BFS(int start, vector<vector<int>> &v, int target){
    queue <int> q;

    q.push(start);
    visited[start] = true;
    return 0;
}

int main(){

    
    cin >> n;
    
    vector<vector<int>> adj(n); // n,weight

    // get zone
    for (int i = 0; i < n; i++){
        cin >> zones[i];
    }


    // ไม่ต้อง push 2 ข้างเพราะโจทย์จะให้ข้อมูลมาเอง
    //get adj list
    while (true){
        char mode;
        int a, b;

        cin >> mode;
        if (mode == 's') break;

        cin >> a >> b;

        adj[a].push_back(b);
    }

   for (int i = 0; i < adj.size(); i++){
    for (int j = 0; j < adj[i].size(); i++){
        cout << adj[i][j] << " ";
    }
    cout << '\n';
   }

    //querries

    // char mode;
    // int a, b;

    // while (true){
    //     cin >> mode;
    //     if (mode == 'q') break;
        
    //     // reset visited, reset parent so that the new starting point is the parent and we can count the step correctly
        
        
    //     cin >> a >> b;
    //     // reset parent
    //     fill(visited.begin(), visited.end(), false);
    //     fill(parent.begin(), parent.end(), -1);

        




return 0;
}