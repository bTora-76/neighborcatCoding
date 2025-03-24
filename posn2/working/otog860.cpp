#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,char> pic;

const int MOD = 1e9 + 7;
string s;
int node, edge;
int start, L;

int mem[151][2501];

int f(int n, int index, vector <vector <pic>>&v){
    // cout << "f(" << n << "," << index << ")\n";
    // cout << "cAll "; 
    // base case
    // มัน 0 index เพราะชะนั้นถ้าเท่ากับ L ก็คือเกิน

    if (mem[n][index] != -1) return mem[n][index];

    if (index == L){
        return 1;
    } // วิ่งมาจนเกิน index สุดท้ายได้ก็คือผ่าน

    int ways = 0;
    char target = s[index];
    
    // loop neighbor
    
    // find neighbors that match target
    
    // loop all neighbors of current node
    for (int i = 0; i < v[n].size(); i++){
        // call all out edges that have weight of target
        if (v[n][i].second == target){
            ways = (ways + f(v[n][i].first,index + 1,v)) % MOD;
        }

        

    }
    // คือถ้ามันหาทางไปไม่ได้ ways ที่ return ในรอบนี้ก็เป็น 0
    return mem[n][index] = ways % MOD;


}

// if(v[n][i] == "") continue;
        // // that string has the target
        // // index starts from 0
        // for (int j = 0; j < v[n][i].size(); j++){
        //     if(v[n][i][j] == target){
        //         // call function
        //         // cout << "deepcall " << i << " ";
        //         ways = (ways + f(i,index + 1,v)) % MOD;
        //         break;

        //     }

        // }


int main(){
    // set mem
    for (int i = 0; i <= 150;i++){
        for (int j = 0; j <= 2500; j++){
            mem[i][j] = -1;
        }
    }


    
    cin >> node >> edge;

    vector <vector <pic>> adj(node+1);

    for (int i = 0; i < edge; i++){
        int a, b; 
        char w; // weight is char
        cin >> a >> b >> w;

        // directed graph
        adj[a].push_back({b,w});
    }

    
    // check adj (correct)
    // for (int i = 1; i <= node; i++){
    //     for (int j = 1; j <= node; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    
    cin >> start >> L;
    

    cin >> s;
    // cout << s;

    cout << f(start, 0, adj);



    return 0;
}