#include<bits/stdc++.h>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
#define MOD 998244353
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
vi dp(5000 + 2, 0);

void solve(int x, int k, bool add){
    // as one ball will combine with every single one of possible so dp[i] is added all ways + x
    if(add){
        for(int i = k - x;i >= 0;i--){
            dp[i + x] = (dp[i + x] + dp[i])%MOD;
        }
    }
    else{
        for(int i = 0;i <= k - x;i++){
            dp[i + x] = (MOD + dp[i + x] - dp[i])%MOD;
        }
    }
}

int main() {
    setIO("check");
    dp[0] = 1;
    int q, k;
    cin >> q >> k;
    while(q--){
        int x;
        char operation;
        cin >> operation >> x;
        solve(x, k, operation == '+');
        cout << dp[k] << '\n';
    }
    return 0;
}
