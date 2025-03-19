#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;




vector <int> zones(7,0);

int n;

// int DFS(int node, vector<vector<int>> &v, int target){

//     if(node == target) return 0;

//     if(node == n-1) return 9999;

//     visited[node] = true;
//     int minVal = 99;

//     vector<int>::iterator it;
//     for (it = v[node].begin(); it != v[node].end(); it++){
//         if(visited[*it] == false){
//             minVal = min(minVal, DFS(*it, v, target));
//         }
            
        
       
//     }

//     return minVal + 1;

// }

vector <int> parent(7,-1);

int bfs(int node, vector<vector<int>> &v, int target){

    // cout << " node " << node << endl;
    queue <int> q;
    q.push(node);

    vector <bool> visited(v.size(),false);
        vector <int> parent(v.size(),-99);
        parent[node] = -1;
    visited[node] = true;
    
    while (!q.empty()){
        int t = q.front();

        visited[t] = true;
        q.pop();

        for(int x : v[t]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
                parent[x] = t;
            }
        }

        // cout << "visited[] = " << endl;
        // for (int i = 0; i < 7; i++) {
        //     cout << visited[i] << " ";
        // }

        // cout << endl << "t = " << t;

        // vector<int>::iterator it;
        // for (it = v[t].begin(); it != v[t].end(); it++){

        //     if(visited[*it] == false){
        //         cout << "\t currnt it = " << *it << endl;
        //         visited[*it] = true;
        //         parent[*it] = t; // set parent
        //         q.push(5);
        //         cout << "front " << q.front() << endl;
        //     }

        //     // if t == target
        //     cout << "T: " << *it;
        //     cout << "TARGET: " << target << '\n';
        // }

        int step = 0;
        int currentParent = target;
        if(parent[target] = -99) return 0;
    
        // cout << "Before: " << n; 
        while(parent[currentParent] != -1){
            currentParent = parent[currentParent];
            // cout << " In Loop: " << n;
            // n = parent[n];
            ++step;
        }
   
        // cout << endl;


        // cout << " After: " << n;

        return step;
    
        
    }
    cout << endl;
         for (int e: parent) {
            cout << e << " ";
        }
        cout << endl;

    // count 
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

    // for (int i = 0; i < adj.size(); i++){
    //     for (int j = 0; j < adj[i].size(); j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    //querries

    char mode;
    int a, b;

    while (true){
        cin >> mode;
        if (mode == 'q') break;
        
        // reset visited, reset parent so that the new starting point is the parent and we can count the step correctly
        
        
        cin >> a >> b;

        // fill(visited.begin(), visited.end(), false);
        // fill(parent.begin(), parent.end(), -1);

        int x = bfs(a, adj, b);

        cout << x;

        // for (int i = 0; i < n; i++){
        //     cout << parent[i] << " ";
        // }



        if (x == 0) cout << " N\n";

        

        else if (mode == 'b'){
            // basic tickets

            // DFS to find shortest number of stops
            if(zones[b] == 1 || zones[b] == 2){
                cout << " Y\n";
            }
            else {cout << " N\n";}
        }
        else {
            cout << " Y\n";
        }
    }



return 0;
}