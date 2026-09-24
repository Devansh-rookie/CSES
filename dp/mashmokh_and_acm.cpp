/*
    state -> (last value used (index should be fine), vals_remaining, )

 */

#include <algorithm>
#include<bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
#define all(x) x.begin(), x.end()
#define nl '\n'
#define MOD 1000000007
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO();

    int n, k;
    cin >> n >> k;

    vector<vi> dp(n + 1, vi(k + 1, 0));
    for(int i = 1;i <= n;i++){
        dp[i][1] = 1;
        for(int j = 2;j <= k;j++){
            for(int var = i;var <= n;var += i){
                dp[var][j] = (dp[var][j] + dp[i][j - 1])%MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = (ans + dp[i][k]) % MOD;
    }
    cout << ans << nl;
    return 0;
}
