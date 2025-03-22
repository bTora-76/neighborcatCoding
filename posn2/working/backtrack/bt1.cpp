#include <iostream>
#include <vector>
using namespace std;

int goal;
int countL = 0;
int countR = 0;

// Recursive binary search function
int binarySearch(int l, int r, vector<int>& v) {
    if (l > r) return -1; // Base case: element not found

    int mid = l + (r - l) / 2;

    if (v[mid] == goal) return mid; // Found the element

    if (v[mid] < goal) {
        ++countR; // Searching right
        return binarySearch(mid + 1, r, v);
    } else {
        ++countL; // Searching left
        return binarySearch(l, mid - 1, v);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cin >> goal;

    int index = binarySearch(0, n - 1, v);
    cout << index << " " << countL << " " << countR;
    return 0;
}
