#include <iostream>
#include <vector>
using namespace std;


int main(){
    

    int node,edge;
    cin >> node >> edge;

    vector<vector <pair<int,int>>> adj(node);


    //get input
    for(int i = 0; i < edge; i++){
        int num1,num2, weight;
        cin >> num1 >> num2 >> weight;
        adj[num1].push_back({num2,weight});
        adj[num2].push_back({num1,weight});
    }
    //output
    for(int i =0; i < adj.size(); i++){

    //ดูทีละแทว
    vector <pair<int,int>>::iterator it;
    cout << i;
    for(it = adj[i].begin();it != adj[i].end();it++){
        cout << " -> " << it->first << " , "<< it->second;
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