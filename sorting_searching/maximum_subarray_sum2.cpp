#include<bits/stdc++.h>
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

int main() {
    // setIO("check");

    int n, a, b;

    cin >> n >> a >> b;

    vector<ll> arr(n);

    for(int i = 0;i < n;i++) cin >> arr[i];
    vector<ll> pref(n+1,0);
    for(int i = 1;i <= n;i++){
        pref[i] = arr[i-1] + pref[i-1];
    }

    multiset<ll> m;
    ll ans = -INFINITY;
    for(int i = a;i <= n;i++){
        if(i > b) m.erase(m.find(pref[i - b - 1])); // to keep number of elements between [a, b] like as b - a + 1

        m.insert(pref[i - a]); // increase the element to b - a + 1

        ans = max(ans, pref[i] - *m.begin());
    }

    cout << ans;

    return 0;
}