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
        cin >> some[i].second >> some[i].first;
    }
    sort(some.begin(), some.end());
    // always take the one which ends earlier as it would give more options in the future
    //

    int ans = 0;
    int lastDeadline = 0;
    for(int i = 0;i < n;i++){
        if(lastDeadline <= some[i].second){
            lastDeadline = some[i].first;
            ans++;
        }
    }

    cout << ans;

    return 0;
}
