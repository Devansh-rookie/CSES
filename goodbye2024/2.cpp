#include <bits/stdc++.h>
using namespace std;

// void solve() {
//     int n;
//     cin >> n;

//     vector<vector<int>> arr(n, vector<int> (2, 0));
//     map<int, int> m;
//     for(int i=0;i < n;i++){
//         cin >> arr[i][0] >> arr[i][1];

//         if(arr[i][0] == arr[i][1]){
//             m[arr[i][0]]++;
//         }
//     }

//     vector<int> present(2*n + 1, 0);
//     for (auto &[key, freq] : m) {
//         if (key <= 2*n) {
//             present[key] = 1;
//         }
//     }

//     vector<int> prefix_present(2*n + 1, 0);
//     for (int i = 1; i <= 2*n; i++) {
//         prefix_present[i] = prefix_present[i - 1] + present[i];
//     }

//     vector<int> ans(n, 1);
//     for (int i = 0; i < n; i++) {
//         int a = arr[i][0], b = arr[i][1];

//         // Calculate actual sum using prefix sums
//         int actual_sum = prefix_present[b] - (a > 1 ? prefix_present[a - 1] : 0);

//         // Calculate expected sum using sum of natural numbers
//         int expected_sum = ((long long)b * (b + 1)) / 2 - ((long long)(a - 1) * a) / 2;

//         // If actual sum doesn't match expected sum, mark as not unique
//         if(expected_sum == actual_sum){
//             ans[i] = 0;
//         }
//         if(arr[i][0] == arr[i][1] && m[arr[i][0]] > 1){
//             ans[i] = 0;
//         }
//     }

//     for (int bit : ans) {
//         cout << bit;
//     }
//     cout << endl;
// }

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2, 0));
    map<int, int> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0] >> arr[i][1];

        if(arr[i][0] == arr[i][1]){
            m[arr[i][0]]++;
        }
    }

    vector<int> present(2 * n + 1, 0);
    for (auto &[key, freq] : m) {
        if (key <= 2 * n) {
            present[key] = 1;
        }
    }

    vector<int> prefix_present(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        prefix_present[i] = prefix_present[i - 1] + present[i];
    }

    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++){
        int a = arr[i][0], b = arr[i][1];
        int count_in_range = prefix_present[b] - prefix_present[a - 1];
        if(arr[i][0] == arr[i][1]){
            if(m[arr[i][0]] > 1)ans[i] = 0;
            continue;
        }
        if(count_in_range == (b - a + 1)){
            ans[i] = 0;
        }
    }

    for(int bit : ans) {
        cout << bit;
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
