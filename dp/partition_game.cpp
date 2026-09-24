#include <bits/stdc++.h>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<long long>> dp;

void solve(int k, int l, int r, int optl, int optr, vector<int>& a) {
    if (l > r) return;

    int mid = (l + r) >> 1;

    long long best = 1e18;
    map<int, pii> m;
    long long s1 = 0;

    m[a[mid]] = {mid, mid};
    optr = min(optr, mid - 1);
    for (int i1 = mid; i1 > optr; i1--) {
        if (!m.count(a[i1])) {
            m[a[i1]] = {i1, i1};
        } else {
            s1 -= m[a[i1]].second - m[a[i1]].first;
            m[a[i1]].first = i1;
            s1 += m[a[i1]].second - m[a[i1]].first;
        }
    }
    int opt = -1;
    for (int val = optr; val >= optl; val--) {
        if (!m.count(a[val])) {
            m[a[val]] = {val, val};
        } else {
            s1 -= m[a[val]].second - m[a[val]].first;
            m[a[val]].first = val;
            s1 += m[a[val]].second - m[a[val]].first;
        }
        if (best > dp[val - 1][k - 1] + s1) {
            best = dp[val - 1][k - 1] + s1;
            opt = val;
        }
    }

    if (opt == -1) return;

    dp[mid][k] = best;

    solve(k, l, mid - 1, optl, opt, a);
    solve(k, mid + 1, r, opt, optr, a);
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp.assign(n + 2, vector<long long>(k + 2, 1e18));

    dp[0][0] = 0;

    for (int i = 1; i <= k; i++) {
        solve(i, i, n, i, n - 1, a);
    }

    cout << dp[n][k] << '\n';

    return 0;
}
