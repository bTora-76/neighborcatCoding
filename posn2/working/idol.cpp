#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

vector <vector <int>> dst; // .ช้ 2d เลยแบบไม่ใช่ adj เพราะมันทุก node ไปทุก node

int getD(pii a, pii b){
    return max(abs(a.first - b.first) , abs(a.second - b.second));


}

int findParent(int n, vector<int>&v){

    if(v[n] == n) return n;

    return v[n] = findParent(v[n],v);

}

int main(){

    int node;
    cin >> node;    

    dst.resize(node, vector<int>(node, 0));

    vector <pii> v(node);

    for (int i = 0; i < node; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x,y};
    }

    // calculate distance between all nodes


    // loop starting nodes
    for (int i = 0; i < node; i++){
        // loop each other distance
        for (int j = 0; j < node; j++){
            if(i == j) continue; // เป็น 0 อยู่แล้ว
            dst[i][j] = getD(v[i],v[j]);
        }
    }


    // for (int i = 0; i < node; i++){
    //     // loop each other distance
    //     for (int j = 0; j < node; j++){
    //         cout << dst[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    vector <int> parent(node);
    // set parent
    for (int i = 0; i < node; i++){
        parent[i] = i;
    }



    // kruskals

    // มองว่า dst คือ inputs

    vector <pair <int,pii>> inputs;

    for (int i = 0; i < node; i++){
        for (int j = 0; j < node; j++){
            if (dst[i][j] != 0){
                inputs.push_back({dst[i][j],{i,j}});
            }
            
        }
    }

    sort(inputs.begin(), inputs.end(), greater<pair <int,pii>>());

    int fans = 0;

    // loop edges in input
    for (int i = 0; i < inputs.size(); i++){
        int a = inputs[i].second.first;
        int b = inputs[i].second.second;
        int w = inputs[i].first;

        int A = findParent(a,parent);
        int B = findParent(b,parent);

        // if parents aren't the same, join
        if(A != B){
            parent[A] = B;
            fans += w;
        }
    }


    cout << fans;

    return 0;
}