#include <bits/stdc++.h>
using namespace std;

bool calc(const vector<long long>& b) {
    int n = b.size();
    vector<int> vis(n, 0);

    function<bool(int, int)> dfs = [&](int cur, int used) {
        if (used == n) return true;

        long long mx = *max_element(b.begin() + cur, b.end());
        long long need = mx - b[cur];

        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;

            if (b[j] == need) {
                vis[j] = 1;

                if (dfs(j, used + 1))
                    return true;

                vis[j] = 0;
            }
        }

        return false;
    };

    for (int start = 0; start < n; start++) {
        fill(vis.begin(), vis.end(), 0);
        vis[start] = 1;

        if (dfs(start, 1))
            return true;
    }

    return false;
}

void ans() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (auto &x : a)
        cin >> x;

    long long cnt = 0;

    sort(a.begin(), a.end());

    do {
        if (calc(a)) {
            cnt++;

            for (auto x : a)
                cout << x << " ";

            cout << '\n';
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "COUNT = " << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ans();
    }

    return 0;
}