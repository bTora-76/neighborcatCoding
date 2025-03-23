#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxVal = -1e9;

int DAC(vector<int> &v){
    
    // choice
    if(v.size() == 1) return v[0];


    int pR = v[v.size()-1];
    v.pop_back(); 
    vector <int> pL = v;

    // ต้องเป็น post order เพราะวิ่งให้ลึกสุดก่อนแล้วค่อยย้อน

    int sum = DAC(pL) + pR; 

    if(sum > pR){
      maxVal = max(maxVal, sum);
      return sum;
    }

    else if (pR >= sum){
      maxVal = max(maxVal, pR);
      return pR;
    }

    return -1;
}

int main(){

    int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int x = DAC(v);

    cout << maxVal;


    return 0;
}