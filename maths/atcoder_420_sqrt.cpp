#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6;

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

    ll x;
    cin >> x;

    ll c = (4*x - 1);
    vll ans;
    for(ll d = 1;d*d <= abs(c);d++){
        if(c % d != 0) continue;
        ll first = (d - (c/d) - 2)/4;
        ll second = (-d +(c/d) - 2)/4;
        ans.pb(first);
        ans.pb(second);
    }
    sort(all(ans));
    cout << ans.size() << '\n';
    for(ll i: ans){
        cout << i << ' ';
    }
    return 0;
}
