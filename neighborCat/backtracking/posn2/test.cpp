#include <iostream>
#include <vector>
#include <string>

using namespace std;

string s;
long long sum = 0;

void generate(int depth, vector<bool> &used, string word, bool flag) {
    if (depth == s.size()) {
        cout << word << '\n';
        return;
    }

    sum++;

    if (flag) {  // Pick characters from right to left
        for (int i = used.size() - 1; i >= 0; i--) {
            if (!used[i]) continue;

            used[i] = false;
            generate(depth + 1, used, word + s[i], i == used.size() - 1);
            used[i] = true;
        }
    } else {  // Pick characters from left to right
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) continue;

            used[i] = false;
            generate(depth + 1, used, word + s[i], i == used.size() - 1);
            used[i] = true;
        }
    }
}

int main() {
    getline(cin, s);
    
    vector<bool> used(s.size(), true);
    generate(0, used, "", false);

    cout << sum << endl;
    return 0;
}
