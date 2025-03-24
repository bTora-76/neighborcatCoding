#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

typedef pair<float,float> pff;


bool comp(pff a, pff b){
    return (a.second/a.first) > (b.second/b.first);
}

int main(){
    int items, maxWeight;
    int sumVal = 0;
    cin >> items >> maxWeight;

    vector <pff> v(items);

    for (int i = 0; i < items; i++){
        float w, val;
        cin >> w >> val;
        v[i] = {w,val};
    } 

    // sort by ratio of (value/price) 

    sort(v.begin(), v.end(), comp);

    // for (auto e : v)cout << e.second/e.first << " ";

    int weight = 0;
    

    for (int i = 0; i < items; i++){
        if(v[i].first + weight <= maxWeight){
            // cout << "ADD: " << v[i].first << " ";
            sumVal += v[i].second;
            weight += v[i].first;
        }
        // process remainder
        else{
            float remainWeight = maxWeight - weight;
            sumVal += (remainWeight * v[i].second/v[i].first);
            weight = maxWeight;

        }

    }

    cout << sumVal;





}