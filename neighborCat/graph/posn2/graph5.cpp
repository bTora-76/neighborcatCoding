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
    
    while (!q.empty()){
        int t = q.front();
        q.pop();
        // cout << t << " ";
        
        // check if equal to target node
        


        // loop neighbors
        for (int i = 0; i < v[t].size(); i++){
            if(visited[v[t][i]] == false){
                visited[v[t][i]] = true;
                q.push(v[t][i]);
                parent[v[t][i]] = t;
            }
        }

        if(t == target){
            int step = 0;
            int curParent = parent[target];
            while(curParent != -1){
                target = curParent;
                curParent = parent[target];
                ++step;
            }
            return step;
        }
    }
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

//    for (int i = 0; i < adj.size(); i++){
//     cout << "INDEX: " << i << " : ";
//     for (int j = 0; j < adj[i].size(); j++){
//         cout << adj[i][j] << " ";
//     }
//     cout << '\n';
//    }



  
// //check parent
//    cout << '\n';
//    for (int e : parent){
//     cout << e << " ";
//    }

    //querries

    char mode;
    int a, b;

    while (true){
        cin >> mode;
        if (mode == 'q') break;
        
        // reset visited, reset parent so that the new starting point is the parent and we can count the step correctly
        
        
        cin >> a >> b;
        // reset parent
        fill(visited.begin(), visited.end(), false);
        fill(parent.begin(), parent.end(), -1);

        int x = BFS(a, adj, b);

        if (x == 0) {
            cout << "0 N\n";
            continue;
        }
        // if distance isn't 0;
        cout << x ;

        if(mode == 'b'){
            // if starting point or ending point is in zones other than 1,2 then invalid
            if((zones[a] != 1 && zones[a] != 2) || (zones[b] != 1 && zones[b] != 2)){
                cout << " N\n";
            }
            else cout << " Y\n";
        }
        else {
            cout << " Y\n";
        }
    }

        




return 0;
}