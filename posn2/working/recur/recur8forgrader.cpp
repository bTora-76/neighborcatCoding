#include <iostream>
#include <vector>
using namespace std;

int recursive_calls = 0;
vector<string> results;

void permute(string &str, int l, int r) {
    if (l == r) {
        results.push_back(str);
    } else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            recursive_calls++;
            permute(str, l + 1, r);
            swap(str[l], str[i]); // backtrack  
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    permute(input, 0, input.size() - 1);
    
    for (const string &s : results) {
        cout << s << "\n";
    }
    cout << recursive_calls + 1 << "\n";
    
    return 0;
}
