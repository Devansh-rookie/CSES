#include <bits/stdc++.h>
#include <ios>
#include <vector>
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
  //   setIO("check");
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> pos_a(n + 2), pos_b(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos_a[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      pos_b[b[i]].push_back(i);
    }
    auto get_next = [&](const vector<int> &pos, int idx) {
      auto it = lower_bound(pos.begin(), pos.end(), idx);
      if (it == pos.end())
        return n + 1;
      return *it;
    };
    vector<int> dp(n + 2, n + 1);
    for (int i = n; i >= 1; i--) {
      if (a[i] == b[i]) {
        int k = a[i];
        int pa = get_next(pos_a[k + 1], i + 1);
        int pb = get_next(pos_b[k + 1], i + 1);
        if (pa == pb && pa == n + 1)
          dp[i] = n + 1;
        else if (pa != pb) {
          dp[i] = min(pa, pb);
        } else { // pa == pb != n+1
          dp[i] = dp[pa];
        }
      }
    }
    long long ans = 0;
    for (int L = 1; L <= n; L++) {
      int pa = get_next(pos_a[1], L);
      int pb = get_next(pos_b[1], L);
      int bad = n + 1;
      if (pa == pb && pa == n + 1) {
        bad = n + 1;
      } else if (pa != pb) {
        bad = min(pa, pb);
      } else {
        bad = dp[pa];
      }
      ans += bad - L;
    }
    cout << ans << '\n';
  }
  return 0;
}