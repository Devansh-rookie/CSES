#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
        ll k;
        cin >> n >> k;
        vector<tuple<int, int, int>> casinos(n);
        for (int i = 0; i < n; ++i) {
            int l, r, real;
            cin >>l>> r>>real;
            casinos[i] ={l, r, real};
        }
        sort(casinos.begin(), casinos.end());
        priority_queue<int> pq;
        int i = 0;
        int ans = k;
        while (true) {
            while (i < n) {
                auto [l, r, real] = casinos[i];
                if (l > k) break;
                if (k <= r) pq.push(real);
                i++;
            }

            if(pq.empty()) break; // glt hogya can't move ahead
            int check = pq.top();
            pq.pop();
            if(check <= k) break; // kuch improve na hua
            // if ok then
            k = check;
        }

        cout << k << '\n';
    }
    return 0;
}
