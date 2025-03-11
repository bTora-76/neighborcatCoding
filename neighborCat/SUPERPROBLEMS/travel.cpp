#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

int getDistance(pair <int,int> point1, pair<int,int> point2){
    return sqrt(pow(point1.first-point2.first,2) + pow(point1.second-point2.second,2));
}

const int inf = 1e9;

int main(){


    int node, edge, r;
    cin >> node;
    pair <int,int> origin;
    cin >> origin.first >> origin.second >> r;

    vector<vector<int>> adj(node, vector<int>(node));
    int dst[node];
    for (int i = 0; i < node;i++){
        dst[i] = inf;
    }
    dst[0] = 0;

    vector <pair<int,int>> inputs(node);

    for (int i = 0; i < node; i++){
        cin >> inputs[i].first >> inputs[i].second;
    }

    // processing adj matrix

    for (int i = 0; i < node; i++){
        for (int j = 0; j < node; j++){
            if(i == j) adj[i][j] = 0;
            else if (getDistance(inputs[i],origin) <= r && getDistance(inputs[j],origin) <= r ){
                adj[i][j] = 0;
            }
            else{adj[i][j] = abs(inputs[i].first - inputs[j].first) + abs(inputs[i].second - inputs[j].second);
            }
        }
    }

    // check matrix
    // for (int i = 0; i < node; i++){
    //     for (int j = 0; j < node; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    

    // dijkstra


    priority_queue<pair <int,int>, vector<pair <int,int>>, greater<pair <int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (int i = 0; i < node; i++){
            // if less than, add
            if ( w + adj[v][i] < dst[i]){
              pq.push({w + adj[v][i], i}); // all distances here are in relation to the starting node 
              dst[i] = w + adj[v][i];
            }
        }
    }

    cout << dst[node - 1];

    return 0;
}