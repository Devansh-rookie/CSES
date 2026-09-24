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
#define nl '\n'

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

    int n;
    cin >> n;
    vpii a(n);

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        string s;
        cin >> s;
        int mask = 0;
        for(char c: s){
            if(c == 'A'){
                mask = mask | (1 << 0);
            }
            else if(c == 'B'){
                mask = mask | (1 << 1);
            }
            else mask = mask | (1 << 2);
        }
        a[i].first = x;
        a[i].second = mask;
    }

    vvi dp(n + 1, vi(1 << 3, INT_MAX));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        for(int mask = 0;mask < (1<<3);mask++){
            if(dp[i-1][mask] == INT_MAX) continue;
            int mi = a[i-1].second;
            dp[i][mask] = min(dp[i][mask], dp[i-1][mask]);
            dp[i][mask | mi] = min(dp[i][mask | mi], dp[i - 1][mask] + a[i-1].first); // since DAG typa thing i guess thats why only once we reach here else we might have needed
            // dp[i][newmask] as well in the min thing
        }
    }
    cout << ((dp[n][7] == INT_MAX)? -1: dp[n][7]) << nl;
    return 0;
}
