#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findParent(int node, vector<int> &parent){
    if (parent[node] == node){
        return node;
    }

    return parent[node] = findParent(parent[node], parent);
}

int main(){

    int n,e;
    cin >> n >> e;

    int cost = 0;

    vector <pair<int, pair<int,int>>> inputs;

    for (int i = 0; i < e; i++){
        int a,b,w;
        cin >> a >> b >> w;
        inputs.push_back({w,{a,b}});
    }

    sort(inputs.begin(), inputs.end());

    vector <int> parent(n+1);

    for (int i = 1; i <= n; i++){
        parent[i] = i;
    }

    //loop inputs
    for (int i = 0; i < e; i++){
        int A = findParent(inputs[i].second.first, parent);
        int B = findParent(inputs[i].second.second, parent);

        if (A != B){
            parent[A] = B;
            cost += inputs[i].first;
        }
    }

    cout << cost - (n - 1);


    return 0;
}