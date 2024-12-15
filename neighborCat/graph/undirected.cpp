#include <iostream>
#include <vector>
using namespace std;

bool adj[500][500] = {false};

int main(){
    int node,edge;
    cin >> node >> edge;


    //get input
    for(int i = 0; i < edge; i++){
        int num1,num2;
        cin >> num1 >> num2;
        adj[num1][num2] = true;
        adj[num2][num1] = true;
    }
    //output
    for(int i =0; i < node; i++){
        cout << i;
        for (int j = 0; j < node; j++){
            if (adj[i][j] == true){
                 cout << " -> " << j;
            }
        }
        cout << '\n';
    }
    return 0;

}