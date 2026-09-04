#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
using ll = long long;
const int MOD = (int)(1e9 + 7);

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

long long dp[20][2][11];
string N;
long long countNumbers(int pos, bool smaller, int last) {
    if (pos == N.size()) return 1;
    if (dp[pos][smaller][last] != -1) return dp[pos][smaller][last];
    int limit = smaller ? 9 : N[pos] - '0';
    long long ans = 0;
    for(int i = 0; i <= limit; i++) {
        bool new_smaller = smaller || i < limit;
        if(last == 10 && i == 0){
            ans += countNumbers(pos + 1, new_smaller, 10);
            continue;
        }
        if (i != last) ans += countNumbers(pos + 1, new_smaller, i);
    }
    return dp[pos][smaller][last] = ans;
}
long long countUpTo(long long n) {
    if (n < 0) return 0;
    N = to_string(n);
    memset(dp, -1, sizeof(dp));
    return countNumbers(0, false, 10);
}
int main() {
    // setIO("check");
    memset(dp, -1, sizeof(dp));
    ll a, b;
    cin >> a >> b;
    cout << countUpTo(b) - countUpTo(a - 1) << endl; // same DP might be able to solve this
    return 0;
}
