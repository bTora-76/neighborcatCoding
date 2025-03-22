#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int goal = 36;

void f(vector <int> &v, vector<int> &current, int index){

    if(accumulate(current.begin(), current.end(),0) == goal){
        // sort back to descending order
        sort(current.begin(),current.end(), greater<int>());
        for (int e : current) cout << e << " ";
        cout << '\n';

        return;
    }   
    sort(v.begin(),v.end());
    for (int i = index; i < v.size(); i++){
        
        current.push_back(v[i]);
        f(v, current, i+1);
        current.pop_back();
    }





}

int main(){

    vector <int> v = {25,10,9,2};
    vector <int> current;
    f(v, current, 0);

    return 0;
}