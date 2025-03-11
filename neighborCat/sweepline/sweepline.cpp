#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n;
    cin >> n;

    priority_queue<pair <int,int>, vector<pair <int,int>>, greater<pair <int,int>>> q;


    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        q.push({a,1});
        q.push({b,-1});
    }

    // process

    int m = 0;
    int count = 0;

    while(!q.empty()){
        count += q.top().second;
        q.pop();
        m = max(m, count);
    }

    cout << m;


    return 0;
}