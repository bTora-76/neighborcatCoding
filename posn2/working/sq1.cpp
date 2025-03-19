#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    // char n;
    // cin >> n;
    // cout << n;
    // cout << typeid(n).name();
    int n,q;
    cin >> n >> q; 

    vector <stack<int>> v(n);

    int mode;
    int t;
    int num;

    for (int i = 0; i < q; i++){
        cin >> mode >> t;
        if (mode == 0){
            cin >> num;
            v[t].push(num);
        }
        else if (mode == 1){
            if(!v[t].empty()){
            cout << v[t].top() << '\n';
            }
        }
        else if (mode == 2){
            // make sure that stack isn't empty
            if (!v[t].empty()){
                v[t].pop();
            }
        }


    }

}


// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// int main() {
//     int n, q;
//     cin >> n >> q;
    
//     vector<stack<int>> stacks(n);
    
//     while (q--) {
//         int cmd, t, x;
//         cin >> cmd >> t;
        
//         if (cmd == 0) { // push operation
//             cin >> x;
//             stacks[t].push(x);
//         } else if (cmd == 1) { // top operation
//             if (!stacks[t].empty()) {
//                 cout << stacks[t].top() << "\n";
//             }
//         } else if (cmd == 2) { // pop operation
//             if (!stacks[t].empty()) {
//                 stacks[t].pop();
//             }
//         }
//     }
    
//     return 0;
// }
