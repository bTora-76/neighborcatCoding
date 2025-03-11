#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

int main(){

    long long n, goal;

    cin >> n >> goal;

    vector <long long> v(n);

    for (long long i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    // L and R represent minimum time and maximum time respectively
    long long L = 1;
    long long R = 1e18;
    long long mid;
    long long ans;

    while(L <= R){
        mid = L + ((R - L)/2);

        long long thisProduct = 0;
        for (long long i = 0; i < n; i++){
            thisProduct += (mid/v[i]); 
            if (thisProduct >= goal) break; // จะได้ไม่ + ค่าเกิน
        }

        
        // cout << "This product: " << thisProduct << '\n';
        // cout << L << " " <<  mid << " " << R << '\n';

        // ถ้ามากกว่า

        // >= เป็นเคส minimum
        if(thisProduct >= goal){
            // ไม่ต้อง set mid เพราะเดี๋ยวจะ recalculate ใหม่ใน loop อยู่ดี
            R = mid - 1;
            ans = mid;
        }
        // <= เป็นเคส maximum
        else if (thisProduct < goal){
            L = mid + 1;
        }
        
    }

    cout << ans;

    return 0;
}