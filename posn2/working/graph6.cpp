#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// วิ่งไป set group


int main(){

    int n;
    cin >> n;

    vector <vector <int>> adj(n);
    vector <bool> visited(n, false);
    // set adj

    while (true){

        int a, b;
        cin >> a >> b;
        
        // break input
        if (a == -1 && b== -1) break;

        adj[a].push_back(b); 
        adj[b].push_back(a);

        
    }

    vector<vector<int>> groups(n+1);

    // group number starts from 1
    int groupNum = 1;
    for (int i = 0; i < n; i++){

        // use BFS

        queue <int> q;
        if (visited[i] == false){
            q.push(i);

            while (!q.empty()){
            int t = q.front();
            q.pop();
            if (visited[t] == false){
                visited[t] = true;
                groups[groupNum].push_back(t);


            // loop neighbor
            for (int j = 0; j < adj[t].size(); j++){
                if(visited[adj[t][j]] == false){
                    q.push(adj[t][j]);
                }
            }
            }
            }

            ++groupNum;
        }
    }

    // for (int e : group){
    //     cout << e << " ";
    // }
    // เก็บ group , worst case คือทุกตัวแยกกัน

    // for (int i = 0; i < groups.size();i++){
    //     sort(groups[i].begin(), groups[i].end());
    // }

    // for (int i = 0; i < groups.size(); i++){
    //     for (int j = 0; j < groups[i].size(); j++){
    //         cout << groups[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    

    // print group
    groupNum -= 1; // มันจะบวกเกินมา
    cout << "Network: " << groupNum << '\n';

    for (int i = 1; i <= n; i++){
        if(groups[i].size() == 0) continue; // skip if no group belongs here

        sort(groups[i].begin(), groups[i].end());

        cout << i << ": ";
        for (int j = 0; j < groups[i].size(); j++){
            cout << groups[i][j] << " ";
        }
        cout << '\n';
    }
    

}