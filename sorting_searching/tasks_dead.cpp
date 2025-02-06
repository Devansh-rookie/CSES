#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
using pii = pair<int, int>;
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
    int n;
    cin >> n;
    vector<pii> some(n);

    for(int i = 0;i < n;i++){
        cin >> some[i].first >> some[i].second;
    }
    sort(some.begin(), some.end());
    // always take the one which ends earlier as it would give more options in the future
    //

    long long ans = 0;
    long long currTime = 0;
    for(int i = 0;i < n;i++){
        currTime += some[i].first;
        ans += some[i].second - currTime;
    }

    cout << ans;

    return 0;
}
