#include <iostream>
#include <vector>
using namespace std;

int getid( vector <bool> &visited,  vector <int> &key){
    int minIndex = -1;
    for (int i = 1; i < key.size(); i++){
        if(visited[i] == false && (minIndex == -1 || key[i] < key[minIndex])){
            minIndex = i;
        }
    }
    return minIndex;
}


int main(){
 
    int n, e, start;
    cin >> n >> e;

    // adj matrix
    vector<vector<int>> adj(n+1, vector<int>(n+1, -1));


    vector <int> key(n+1, 1e9);
    vector <bool> visited(n+1,false);
    vector <int> parent(n+1);

    

    
    // set everything to -1, -1 means cannot go, 0 means the same node

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = -1;
        }
    }

    // get input

    for (int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;

        adj[a][b] = w;
        adj[b][a] = w;
    }

    cin >> start;

    key[start] = 0;
    parent[start] = -1;
    
    // each iteration will find min key >> add new node with least weight to list
    for (int i = 0; i < n; i++){
        int minIndex = getid(visited, key);
        if (minIndex == -1)break;
        visited[minIndex] = true;

        // loop neighbors

        for (int j = 1; j <= n; j++){
            // last chunk is used to see if is neighbor
            if(visited[j] == false && adj[minIndex][j] >= 0){
                //check if the weight is less than the current key in order to update
                if(adj[minIndex][j] < key[j]){
                    key[j] = adj[minIndex][j];
                    parent[j] = minIndex; // j คือตัวที่ไปหา, minIndex คือตัวที่เริ่ม
                }

            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << -1; // MST is not possible
            return 0;
        }
    }

    
    
    // start from index 1

    // for (int e : key){
    //     cout << e << " ";
    // }
    int sum = 0;
    for (int i = 1; i <= n; i++){
        if(key[i] == 1e9){
            cout << -1; 
            return 0;
        }
        sum += key[i];
    }

    cout << sum;


    return 0;


}