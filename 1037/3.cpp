#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

using ll = long long;

int main() {
    // setIO("check");
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;
        set<ll> s;
        ll start_height = 0;
        // vector<long long> h(n);
        ll val;

        for (int i = 0; i < n; i++) {

            cin >> val;
            s.insert(val);
            if(i == k){
                start_height = val;
            }
        }
        ll current_time = 0;
        ll h_curr = start_height;
        bool possible = true;

        while (true) {
            auto it = s.find(h_curr);

            if (++it == s.end()) {
                break;
            }

            ll h_next = *it;
            if (current_time > 2 * h_curr - h_next) {
                possible = false;
                break;
            }
            current_time += (h_next - h_curr);
            h_curr = h_next;
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
