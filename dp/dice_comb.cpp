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

int main() {
    // setIO("check");
    ll n;
    cin >> n;

    vi dp = vi(n+1, 0);

    dp[0] = 1;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            if(i - j >= 0){
                dp[i] = (dp[i] + dp[i - j])%MOD;
            }
        }
    }

    cout << dp[n]%MOD;

    return 0;
}