#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> inputs(n);

    for (int i = 0; i < n; i++){
        cin >> inputs[i];
    }

    // process

    for (int i = 0; i < n; i++){
        vector <int> ans = {1}; // 1 is always eligible
        // process each query
        
        // n is even

        for (int j = 2; j < inputs[i]; j++){
            if(__gcd(inputs[i], j) != 1){
                continue;
            }
            // even n can't have even in ans
            if (inputs[i] %2 == 0 && j %2 == 0){
                continue;
            }

            ans.push_back(j);
        }



        // if(inputs[i] %2 == 0){
        //     for (int j = 1; j < inputs[i]; j++){
        //         // check factor and isEven
        //         if(inputs[i] % j == 0 || j %2 == 0){
        //             continue;
        //         }
        //         ans.push_back(j);
        // }
        
        // }
        // // n is odd
        // else {
        //     for (int j = 1; j < inputs[i]; j++){
        //         // check factor
        //         if(inputs[i] % j == 0){
        //             continue;
        //         }

        //         ans.push_back(j);
        //     }
        // }


        cout << ans.size() << '\n';
        for (int e : ans){
            cout << e << " ";
        }
        cout << '\n';
    }

}