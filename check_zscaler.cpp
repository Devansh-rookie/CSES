#include <bits/stdc++.h>
using namespace std;

long getMinimumOperations(std::vector<int> arr) {
    int n = arr.size();
    if (n <= 1) return 0;

    long long operations = 0;
    long long maxAllowed = arr[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        long long value = arr[i];

        if (value > maxAllowed) {
            long long parts = (value + maxAllowed - 1) / maxAllowed;
            operations += parts - 1;
            maxAllowed = value / parts;
        } else {
            maxAllowed = value;
        }
    }

    return operations;
}

int main() {
    vector<int> test = {2, 2, 2, 3};
    cout << getMinimumOperations(test) << "\n";
}
