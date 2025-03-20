#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getMinId(vector <int> &key, vector <bool> &visited){
    int minIndex = -1;
    for (int i = 0; i < key.size(); i++){
        if(!visited[i] && (minIndex = -1 || key[i] < key[minIndex])){
            // update minIndex
            minIndex = i;
        }
    }
    return minIndex;
}

int main(){
    int n, e;
    cin >> n >> e;

    vector <vector <pair<int,int>>> adj(n+1);

    vector <int> key(n+1, 1e9);
    vector <bool> visited(n+1, false);
    // ไม่ต้องมี parent ก็ได้ โจทย์ไม่เอา


    for (int i = 0; i < e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    
    int start;
    cin >> start;


    // process dijkstra

    key[start] = 0;
    visited[start] = true;

    for (int i = 0; i < n; i++){
        // get min index
        int minId = getMinId(key,visited);
        visited[minId] = true;  // วิ่งมาที่ตัว minId แล้ว

        // loop neighbors
        for (int j = 0; j < adj[i].size(); j++){
            if(!visited[j] && adj[minId][j].second != 0 && adj[minId][j].second < key[j]){
                key[j] = adj[minId][j].second;


            }
        }

    }
    
    for (int e : key){
        cout << e << " ";
    }

    // int sum = 0;
    // for (int i = 1; i <= n; i++){
    //     sum += key[i];
    // }
    // cout << sum;

    
    
    return 0;

}