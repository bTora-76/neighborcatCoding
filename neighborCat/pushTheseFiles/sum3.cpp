#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, goal;
    cin >> n >> goal;

    vector <pair<int,int>> inputs(n); // {value, og index}

    for (int i = 0; i < n; i++){
        cin >> inputs[i].first;
        inputs[i].second = i+1;
    }

    sort(inputs.begin(), inputs.end());

    int L = 0;
    int R = n-1;
    int mid = L + ((R-L)/2);
    int sum;

    while (L != mid && R != mid && L < R){
        sum = inputs[L].first + inputs[mid].first + inputs[R].first;

        if (sum == goal){
            cout << inputs[L].second << " " << inputs[mid].second << " " <<  inputs[R].second;
            return 0;
        }

        else if (sum < goal){
            ++L;
        }

        else if (sum > goal){
            --R;
        }
        mid = L + ((R-L)/2);
    }

    cout << "IMPOSSIBLE";

    return 0;
}