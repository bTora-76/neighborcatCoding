#include <iostream>
#include <vector>
using namespace std;

int goal;

int DAC(int L, int R, vector<int> &v){
    int mid = L + (R-L)/2;

    if(L == R && v[L] != goal) return -1; // ถ้าดูตัวสุดท้ายแล้วยังไม่ตรงอีก (L จะทับ R)
    if(v[mid] == goal) return mid;

    // go search left
    if (v[mid] > goal){
      return  DAC(L, mid,v);
    }

    //search right
    else if (v[mid < goal]){
      return  DAC(mid+1,R,v);
    }

    // not found
    return -1;

}

int main(){

    int n;
    cin >> n;

    vector <int> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++){
        cin >> goal;
        cout << (DAC(0,n-1, v) == -1 ? "Not found" : "Found")<< '\n'; 
    }



    return 0;
}