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
using pll = pair<ll, ll>;
int main() {
    // setIO("check");

    int n;
    ll x;

    cin >> n >> x;

    vector<ll> arr(n, 0);

    for(int i = 0;i < n;i++) cin >> arr[i];
    map<ll, pll>m;
    // store all combos in a map for best lookup time then do like 3 sum
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            m[arr[i] + arr[j]] = {i, j};
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            ll target_for_loop = x - arr[i] - arr[j];
            if(m.find(target_for_loop) != m.end()){
                set<ll>s;
                s.insert(i);s.insert(j);s.insert(m[target_for_loop].first);s.insert(m[target_for_loop].second);
                if(s.size() == 4){
                    for(auto k: s){
                        cout << k + 1 << ' ';
                    }
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}