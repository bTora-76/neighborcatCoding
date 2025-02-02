#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    long long n, goal;
    cin >> n >> goal;

    vector <pair<long long,long long>> inputs(n); // {value, og index}

    for (long long i = 0; i < n; i++){
        cin >> inputs[i].first;
        inputs[i].second = i+1;
    }

    sort(inputs.begin(), inputs.end());

    long long L = 0;
    long long R = n-1;
    long long mid = L + ((R-L)/2);
    long long sum;

    while (L < mid && R > mid){
        sum = inputs[L].first + inputs[mid].first + inputs[R].first;

        cout << L << " " << mid << " " << R << " Sum: " << sum << '\n';

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