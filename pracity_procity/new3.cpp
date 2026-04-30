#include <bits/stdc++.h>
#include <iterator>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    // setIO("check");

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<pair<int, int>> sorted;
        for (int i = 0;i < n;i++) {
            sorted.emplace_back(-a[i], i);  // Sort by descending value, then by index
        }
        sort(sorted.begin(), sorted.end());

        unordered_set<int> pressed;
        int clones = 0;

        for(auto& p : sorted){
            int idx = p.second;
            bool need_new = true;
            if(pressed.count(idx - 1) || pressed.count(idx + 1)){
                need_new = false;
            }
            if(need_new){
                clones++;
            }
            pressed.insert(idx);
        }

        cout << clones << endl;
    }

    return 0;
}
