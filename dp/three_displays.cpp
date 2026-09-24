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
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi dp;

int solve(int index, int last_used, int val_left, vi &s, vi &c){ // arr -> val, index
    int n = s.size();
    if(val_left == 0) return 0;
    if(index == n) return 1e9;
    int id = (index*(n+1)+ (last_used+1))*4 + val_left;
    if(dp[id] != INT_MAX) return dp[id];
    int state_ans = solve(index + 1, last_used, val_left, s, c);

    if(last_used == -1 || s[index] > s[last_used]) {
        int temp = solve(index + 1, index, val_left - 1, s, c);
        if(temp != 1e9)
            state_ans = min(state_ans, c[index] + temp);
    }
    return dp[id] = state_ans;
}

int main() {
    setIO();

    int n;
    cin >> n;
    vi s(n), c(n);

    for(int i = 0;i < n;i++) cin >> s[i];
    for(int i = 0;i < n;i++) cin >> c[i];
    dp.assign((n + 1) * (n + 1) * 4, INT_MAX);
    int ans = solve(0, -1, 3, s, c);
    cout << (ans == 1e9? -1 :ans)<< nl;
    return 0;
}
