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
    vector<int> c(n, 0);
    long long goodcards = 0;
    long long clusters = 0;
    long long badcards = 0;
    for (int i = 0; i < n; i++) {
      cin >> c[i];

      if (c[i] >= 2) {
        goodcards += c[i];
        clusters++;
      } else {
        badcards += c[i];
      }
    }
    long long ans = 0;
    if (clusters == 0) {
      ans = 0;
    } else if (clusters == 1) {
      long long slots = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] >= 2) {
          slots = c[i] / 2;
          break;
        }
      }
      ans += goodcards + min(slots, badcards);
    } else {
      long long slots = 0;
      for (int i = 0; i < n; i++) {
        if (c[i] >= 2) {
          slots += c[i] / 2 - 1;
        }
      }
      ans += goodcards + min(slots, badcards);
    }
    if (ans < 3)
      cout << 0 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}