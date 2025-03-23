#include <iostream>
#include <vector>
using namespace std;

int d, poison;

int f(int n, int p, vector<int>&v){
    // base case 
    if(n < 0) return 0;
    if(n == 0) return 0; // we dont do anything at 0 because we add v[0] after the call 

    // use backtracking

    int maxCheese = -9999;

    // first layer
    if (n == d){
        for (int i = n-1; i >= 0; i--){
            // ยังไม่ใช้ยาพิษ
            maxCheese = max(maxCheese, f(i, p, v) + v[i]); //poison is 0 for sure
        }
    }

    else {
        // ถ้ามียาพิษจะลองเรียกตัวที่อยู่ติดได้
        if(p >= 1){
            --p;
            maxCheese = max (maxCheese, f(n-1, p, v) + v[n-1]);
            ++p;
        }
        // สามารถ loop ที่เหลทอได้อีกด้วย
        for (int i = n-2; i >= 0; i--){
            maxCheese = max (maxCheese, f(i, p, v) + v[i]);
        }        
    }


    return maxCheese;

    
    return 0;
}


int main(){

    
    cin >> d >> poison;

    vector <int> v(d+1);

    for (int i = 0; i < d; i++){
        cin >> v[i];
    }

    // start from space outside 1 slot
    cout << f(d, poison, v);
    

    return 0;
}