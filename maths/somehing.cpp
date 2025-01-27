#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXX = 1e6;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<int> dp(MAXX+1);

void phi_1_to_n(int n) {
    // vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i] = i;

    for (int i = 2; i <= n; i++) {
        if (dp[i] == i) {
            for (int j = i; j <= n; j += i)
                dp[j] -= dp[j] / i;
        }
    }
}

void solve(int n){
    ll odd = 0;
    ll even = 0;

    for(int i = 1;i <= n;i++){
        if(i % 2) odd += dp[i];
        else even += dp[i];
    }

    cout << abs(even - odd) << endl;
}


int main() {
    setIO("check");

    phi_1_to_n(MAXX+1);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        solve(n);
    }

    return 0;
}