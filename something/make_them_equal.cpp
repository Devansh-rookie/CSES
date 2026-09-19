#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <utility>
#include <vector>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e3;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vi minop(MAXN + 1, MAXN + 1);
struct DefaultInt {
    int value = INT_MIN;
};
void precompute(){
    minop[1] = 0;
    for(int a = 1;a <= MAXN;a++){
        for(int x = 1;x <= a;){
            int q = a / x;
            // next affected
            int next = a + q;
            if(next <= MAXN)
                minop[next] = min(minop[next], minop[a] + 1);;
            x = a / q + 1;
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi b(n, 0), c(n, 0);
    for(int i = 0;i < n;i++) cin >> b[i];
    for(int i = 0;i < n;i++) cin >> c[i];
    int cap = 0;
    for(int x : b) cap += minop[x];
    cap = min(cap, k);
    vvi dp(n + 1, vi(cap + 1, INT_MIN));
    for(int kk = 0;kk <= cap;kk++){
        dp[0][kk] = 0;
    }
    for(int i = 1;i <= n;i++){
        // if(minop[b[i-1]] > k) continue;
        int val = minop[b[i - 1]];
        for(int kk = 0; kk <= cap;kk++){
            dp[i][kk] = dp[i - 1][kk];
            if(kk >= val) dp[i][kk] = max(dp[i][kk], dp[i - 1][kk - val] + c[i-1]);
        }
    }
    cout << dp[n][cap] << '\n';
}

int main() {
    setIO("");
    precompute();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
