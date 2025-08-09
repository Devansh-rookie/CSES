#include<bits/stdc++.h>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll x, ll y) {
    return x /gcd(x,y) * y;
}


int main() {
    // setIO("check");
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> p(n);
        vector<ll> s(n);

        for(int i = 0;i < n;i++){
            cin >> p[i];
        }
        for(int i = 0;i < n;i++){
            cin >> s[i];
        }

        vector<ll> a(n, 0);

        for(int i = 0;i < n;i++){
            a[i] = lcm(p[i], s[i]);
        }

        vector<ll> pre(n);
        vector<ll> suff(n);
        pre[0] = a[0];
        for(int i = 1;i < n;i++){
            pre[i] = gcd(pre[i - 1], a[i]);
        }
        suff[n - 1] = a[n - 1];
        for(int i = n - 2;i >= 0;i--){
            suff[i] = gcd(suff[i + 1], a[i]);
        }

        if(pre == p && suff == s) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
