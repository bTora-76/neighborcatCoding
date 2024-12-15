#include <iostream>
#include <vector>
using namespace std;


int main(){
    

    int node,edge;
    cin >> node >> edge;

    vector<vector<int>> adj(node);


    //get input
    for(int i = 0; i < edge; i++){
        int num1,num2;
        cin >> num1 >> num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }
    //output
    for(int i =0; i < adj.size(); i++){

    //ดูทีละแทว
    vector <int>::iterator it;
    cout << i;
    for(it = adj[i].begin();it != adj[i].end();it++){
        cout << " -> " << *it;
    }
    cout << '\n';
    //     cout << i;
    //     for (int j = 0; j < adj[i].size(); j++){
    //         cout << " -> " << adj[i][j];
    //     }
    //     cout << '\n';
    }

    
    return 0;

}