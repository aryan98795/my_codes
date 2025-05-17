#include <bits/stdc++.h>
using namespace std;

// Dutch National Flag Algorithm
// Sort an array of 0s, 1s, and 2s in O(n) time and O(1) space
// Asked in Microsoft IIT BHU intern interview (2021)

// Invariant maintained:
// [0 ... low-1]    → all 0s
// [low ... mid-1]  → all 1s
// [mid ... high]   → unknown
// [high+1 ... n-1] → all 2s

void custom_sort(vector<int>& v) {
    int low = 0, mid = 0, high = v.size() - 1;
    while (mid <= high) {
        if (v[mid] == 0) {
            swap(v[mid++], v[low++]);
        } else if (v[mid] == 1) {
            mid++;
        } else {                     // v[mid] == 2
            swap(v[mid], v[high--]); // Don't increment mid here
        }
    }
}

int32_t main() {
    vector<int> v{1, 0, 1, 0, 1, 1, 0, 1, 2, 0};

    cout << "Before sorting: ";
    for (auto& i : v) cout << i << " ";
    cout << "\n";

    custom_sort(v);

    cout << "After sorting: ";
    for (auto& i : v) cout << i << " ";
}
