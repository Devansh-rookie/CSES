#include<bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vll = vector<ll>;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    setIO("");

    int n, m;
    cin >> n >> m;
    vll a(n, 0), b(m, 0);
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) cin >> b[i];
    ll a1 = *min(all(a));
    vll c(n, 0);
    ll g = 0;
    for(int i = 0;i < n;i++){
        c[i] = a[i] - a1;
        g = gcd(g, c[i]);
    }
    for(int i = 0;i < m;i++){
        cout << abs(gcd(a1 + b[i], g)) << ' ';
    }
    return 0;
}
