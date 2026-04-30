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

int main() {
    // setIO("check");
    int mod = 1e9 + 7;
    int x, y;
    cin >> x >> y;

    vector<int> ans(6, 0);

    ans[0] = x;
    ans[1] = y;
    ans[2] = y - x;
    ans[3] = -x;
    ans[4] = -y;
    ans[5] = -y + x;

    int n;
    cin >> n;
    n--;
    cout <<(mod + ans[n%6]%mod)%mod;

    return 0;
}
