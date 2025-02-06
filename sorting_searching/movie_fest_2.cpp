#include<bits/stdc++.h>
#include <cstdio>
#include <set>
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
    int n, k;
    cin >> n >> k;
    vector<pii> some(n);

    for(int i = 0;i < n;i++){
        cin >> some[i].second >> some[i].first;
    }
    sort(some.begin(), some.end());
    // always take the one which ends earlier as it would give more options in the future
    //
    multiset<int> m;
    int ans = 0;
    for(int i = 0;i < n;i++){
        // it would be optimal to get the vals which are the largest and we can assigne something to them
        auto it = m.upper_bound(some[i].second);
        if(it != m.begin()){
            ans++;
            it--;
            m.erase(it);
            m.insert(some[i].first);
        }
        else if(m.size() < k){
            m.insert(some[i].first);
            ans++;
        }
    }

    cout << ans;

    return 0;
}
