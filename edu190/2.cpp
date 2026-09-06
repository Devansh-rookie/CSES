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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> p13(n + 1, 0);
    vector<int> p2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      p13[i] = p13[i - 1] + (s[i - 1] == '1' || s[i - 1] == '3');
      p2[i] = p2[i - 1] + (s[i - 1] == '2');
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int ones = p13[n] - p13[i - 1];
      int twos = p2[i];
      ans = max(ans, ones + twos);
    }
    cout << n - ans << '\n';
  }
  return 0;
}