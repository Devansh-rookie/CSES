#include <bits/stdc++.h>
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
    int n, a, b;
    cin >> n >> a >> b;
    long long ans = 0;
    if (b / 3 < a)
      ans += 1LL * (n / 3) * b;
    else
      ans += 1LL * (n / 3) * a * 3;
    if (n % 3 == 1)
      ans += min(a, b);
    if (n % 3 == 2)
      ans += min(2 * a, b);
    cout << ans << '\n';
  }
  return 0;
}