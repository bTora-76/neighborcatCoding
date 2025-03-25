#include <iostream>
#include <vector>
using namespace std;


int d, poison;

vector <vector <int> > mem;

int f(int n, int p, vector<int>&v){

    //basecase 
    if(n == 0) return v[0];
    if(n < 0) return 0;  

    if(n >=0 && p >= 0 && mem[n][p] != -1)  return mem[n][p];

    //choice 

    int maxVal = 0;

    // ใช้ยา 

    if (p>0){
        maxVal = max(maxVal, f(n-1,p-1,v) + v[n]);
    }

    // กินแล้วเดิน (เลือก)
    maxVal = max(maxVal, f(n-2,p,v) + v[n]);
    // เดิน (ไม่เลือก)
    maxVal = max(maxVal, f(n-1,p,v));

    return mem[n][p] = maxVal;




}


int main(){

    cin >> d >> poison;

    mem.resize(d,vector<int>(poison+1,-1));

    int maxCheese = 0;

    vector <int> v(d);

    for (int i = 0; i < d; i++){
        cin >> v[i];
    }

    maxCheese = f(d-1, poison, v);

    cout << maxCheese;



    return 0;
}