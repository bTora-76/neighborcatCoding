#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



vector <bool> visited(100,false);



int main(){

    int n;
    cin >> n;

    bool flag = false;

    while (true){
        char mode;
        int a, b, w;

        cin >> mode;
        if (mode == 's') break;

        cin >> a >> b >> w;

        visited[a] = true;

        if(visited[b] == true){
            flag = true;
        }

        


    }

    cout << (flag == true ? "Cycle" : "No Cycle");
}



// int getParent(int n ,vector <int> &p){

//     if (p[n] == n){
//         return n;
//     }

//     return p[n] = getParent(p[n], p);

// }

// // preprocess
//         int A = getParent(a, parent);
//         int B = getParent(b, parent);

//         //if input repeats like 0 1, 1 0, it will only join once cuz the second time the parent of 0 is already 1
//         if (A != B){
//             parent[A] = B;
//         }