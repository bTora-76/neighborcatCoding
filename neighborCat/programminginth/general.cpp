#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int getParent (int node, vector <int> & parent){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = getParent(parent[node],parent);

}

int comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}


int main(){

    // inputs

    int n, e;
    cin >> n >> e;


    vector <int> parent(n+1);
    // preset parent of each node to that node
    for (int i = 1; i <= n;i++){
        parent[i] = i;
    }

    vector <int> minion(n+1);

    for (int i = 1; i <= n;i++){
        cin >> minion[i];
    }

    // vector<pair<int,int>> fights(e);

    // for (int i = 0; i < e; i++){
       
    //     pair <int,int> p = {a,b};
    //     // if is dupe
    //     if(find(fights.begin(),fights.end(), p) != fights.end()){
    //         fights[i].first = -1;
    //     }
    //     else{
    //         fights[i].first = a;
    //         fights[i].second = b;
    //     }
        
        
    // }

    
    for (int i = 0; i < e; i++){
        int a,b;
        cin >> a >> b;
        

        int foe1 = a;
        int foe2 = b;
        

        int p1 = getParent(foe1,parent);
        int p2 = getParent(foe2,parent);

        if(p1 == p2){
            cout << -1 << '\n';
            continue;
        }

        if (minion[p1] > minion[p2]){
            minion[p1] += minion[p2]/2;
            parent[p2] = p1; 
            cout << p1;
        }

        else if (minion[p1] < minion[p2]){
            minion[p2] += minion[p1]/2;
            parent[p1] = p2; 
            cout << p2;
        }
        
        // เท่ากัน
        else{
            int winner = min(p1,p2);
            int loser = max(p1,p2);

            minion[winner] += minion[loser]/2;
            parent[loser] = getParent(winner,parent);
            cout << winner;
            
        }

        if (i < e - 1){
            cout << '\n';
        }
        

    }

    

}