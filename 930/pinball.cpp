#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi cnt(n+1, 0);
    vi left(n+1, 0);
    vi right(n+1, 0);

}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
