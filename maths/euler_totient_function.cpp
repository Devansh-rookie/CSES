#include<bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) x.begin(), x.end()
using ll = long long;
const int MOD = (int)(1e9 + 7);
const int MAXN = 1e6 + 1;
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void precompute(vi &phi) {
    for(int i = 2;i < MAXN; i++) {
        if(phi[i] == i){
            for(int j = i;j < MAXN;j+=i){
                phi[j] = phi[j] - phi[j]/i;// n*(1 - 1/p)
            }
        }
    }
}

int main() {
    // setIO("check");

    vi phi(1e6 + 1);
    iota(all(phi), 0);
    precompute(phi);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << phi[n] << '\n';
    }

    return 0;
}
